cmake_minimum_required(VERSION 2.8.8)

project(SemantisedTriangleMesh)
set(version 1.0)

set(SEMANTISED_TRIANGLE_MESH ${CMAKE_CURRENT_SOURCE_DIR})


add_definitions(-DTRIANGLE_HEADER="${TRIANGLE}shewchuck_triangle.h")
    set(AS_LIBRARY true)
set(TRIANGLE ${SEMANTISED_TRIANGLE_MESH}/triangle )
set(DATA_STRUCTURES ${SEMANTISED_TRIANGLE_MESH}/DataStructures )
add_subdirectory(${DATA_STRUCTURES})
add_subdirectory(${TRIANGLE})
set( Srcs
    ${SEMANTISED_TRIANGLE_MESH}/src/Vertex.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/Edge.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/Triangle.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/TriangleMesh.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/annotationfilemanager.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/annotation.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/pointannotation.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/lineannotation.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/surfaceannotation.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/attribute.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/geometricattribute.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/euclideanmeasure.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/geodesicmeasure.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/boundingmeasure.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/semanticattribute.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/relationship.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/KDTree.cpp
)
set( Hdrs
    ${SEMANTISED_TRIANGLE_MESH}/include/Vertex.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/Point.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/Edge.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/Triangle.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/TriangleMesh.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/annotationfilemanager.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/annotation.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/pointannotation.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/lineannotation.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/surfaceannotation.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/attribute.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/euclideanmeasure.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/geodesicmeasure.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/boundingmeasure.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/geometricattribute.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/semanticattribute.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/CommonDefinitions.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/quadtree.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/KDTree.hpp
    ${SEMANTISED_TRIANGLE_MESH}/include/relationship.hpp
)

set(TriangleHdrs ${TRIANGLE}/shewchuk_triangle.hpp ${TRIANGLE}/trianglehelper.hpp)


set(DataStructuresHdrs
    ${DATA_STRUCTURES}/include/node.hpp
    ${DATA_STRUCTURES}/include/arc.hpp
    ${DATA_STRUCTURES}/include/graph.hpp
    ${DATA_STRUCTURES}/include/tree.hpp )
add_library(${PROJECT_NAME} ${Srcs} ${Hdrs})
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${SEMANTISED_TRIANGLE_MESH}/include/> $<BUILD_INTERFACE:${TRIANGLE}/> $<BUILD_INTERFACE:${DATA_STRUCTURES}/include/> )
target_link_libraries(${PROJECT_NAME} PUBLIC Triangle-lib DataStructures-lib)

add_executable(${PROJECT_NAME}-test ${SEMANTISED_TRIANGLE_MESH}/main.cpp ${Srcs} ${Hdrs})
target_include_directories(${PROJECT_NAME}-test PUBLIC $<BUILD_INTERFACE:${SEMANTISED_TRIANGLE_MESH}/include/> $<BUILD_INTERFACE:${TRIANGLE}/> $<BUILD_INTERFACE:${DATA_STRUCTURES}/include/>)
target_link_libraries(${PROJECT_NAME}-test PUBLIC Triangle-lib DataStructures-lib)

install(FILES ${Hdrs} ${TriangleHdrs} ${DataStructuresHdrs} DESTINATION include/${PROJECT_NAME}-${version})
install(TARGETS ${PROJECT_NAME} Triangle-lib DataStructures-lib
        DESTINATION lib/${PROJECT_NAME}-${version}
        EXPORT ${PROJECT_NAME}-targets)

install(EXPORT ${PROJECT_NAME}-targets
        DESTINATION lib/${PROJECT_NAME}-${version})

configure_file(
   ${SemantisedTriangleMesh_SOURCE_DIR}/pkg/semantisedtrianglemesh-config.cmake.in
   ${SemantisedTriangleMesh_BINARY_DIR}/pkg/semantisedtrianglemesh-config.cmake @ONLY)

configure_file(
   ${SemantisedTriangleMesh_SOURCE_DIR}/pkg/semantisedtrianglemesh-config-version.cmake.in
   ${SemantisedTriangleMesh_BINARY_DIR}/pkg/semantisedtrianglemesh-config-version.cmake @ONLY)

install(FILES ${SemantisedTriangleMesh_BINARY_DIR}/pkg/semantisedtrianglemesh-config.cmake
         ${SemantisedTriangleMesh_BINARY_DIR}/pkg/semantisedtrianglemesh-config-version.cmake
         DESTINATION lib/${PROJECT_NAME}-${version})


