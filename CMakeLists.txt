cmake_minimum_required(VERSION 2.8.8)

project(SemantisedTriangleMesh)
set(version 1.0)

set(SEMANTISED_TRIANGLE_MESH ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DTRIANGLE_HEADER="${TRIANGLE}shewchuck_triangle.h")
    set(AS_LIBRARY true)
set(TRIANGLE ${SEMANTISED_TRIANGLE_MESH}/triangle )
add_subdirectory(${TRIANGLE})
set( Srcs
    ${SEMANTISED_TRIANGLE_MESH}/src/Vertex.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/Edge.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/Triangle.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/TriangleMesh.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/annotation.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/pointannotation.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/lineannotation.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/surfaceannotation.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/attribute.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/geometricattribute.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/semanticattribute.cpp
    ${SEMANTISED_TRIANGLE_MESH}/src/facet.cpp
)
set( Hdrs
    ${SEMANTISED_TRIANGLE_MESH}/include/Vertex.h
    ${SEMANTISED_TRIANGLE_MESH}/include/Point.h
    ${SEMANTISED_TRIANGLE_MESH}/include/Edge.h
    ${SEMANTISED_TRIANGLE_MESH}/include/Triangle.h
    ${SEMANTISED_TRIANGLE_MESH}/include/TriangleMesh.h
    ${SEMANTISED_TRIANGLE_MESH}/include/annotation.h
    ${SEMANTISED_TRIANGLE_MESH}/include/pointannotation.h
    ${SEMANTISED_TRIANGLE_MESH}/include/lineannotation.h
    ${SEMANTISED_TRIANGLE_MESH}/include/surfaceannotation.h
    ${SEMANTISED_TRIANGLE_MESH}/include/attribute.h
    ${SEMANTISED_TRIANGLE_MESH}/include/geometricattribute.h
    ${SEMANTISED_TRIANGLE_MESH}/include/semanticattribute.h
    ${SEMANTISED_TRIANGLE_MESH}/include/facet.h
    ${SEMANTISED_TRIANGLE_MESH}/include/CommonDefinitions.h
    ${SEMANTISED_TRIANGLE_MESH}/include/quadtree.h
)

set(TriangleHdrs ${TRIANGLE}/shewchuk_triangle.h ${TRIANGLE}/trianglehelper1.h)

add_library(${PROJECT_NAME} ${Srcs} ${Hdrs})
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${SEMANTISED_TRIANGLE_MESH}/include/> $<BUILD_INTERFACE:${TRIANGLE}/>)
target_link_libraries(${PROJECT_NAME} Triangle-lib)

add_executable(${PROJECT_NAME}-test ${SEMANTISED_TRIANGLE_MESH}/main.cpp ${Srcs} ${Hdrs})
target_include_directories(${PROJECT_NAME}-test PUBLIC $<BUILD_INTERFACE:${SEMANTISED_TRIANGLE_MESH}/include/> $<BUILD_INTERFACE:${TRIANGLE}/>)
target_link_libraries(${PROJECT_NAME}-test Triangle-lib)


install(FILES ${Hdrs} ${TriangleHdrs} DESTINATION include/${PROJECT_NAME}-${version})
install(TARGETS ${PROJECT_NAME} Triangle-lib
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


