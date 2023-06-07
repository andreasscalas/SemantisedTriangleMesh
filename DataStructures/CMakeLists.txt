cmake_minimum_required(VERSION 2.8.8)
project(DataStructures CXX)

if(NOT DEFINED DATA_STRUCTURES)
	set( DATA_STRUCTURES ${CMAKE_SOURCE_DIR})
endif()
#set( Srcs
#    ${DATA_STRUCTURES}/src/list.cpp)

set( GraphMainSrcs
    ${DATA_STRUCTURES}/src/testGraph.cpp)

set( TreeMainSrcs
    ${DATA_STRUCTURES}/src/testTree.cpp)

file(GLOB Hdrs "${DATA_STRUCTURES}/include/*.hpp")

include_directories(
    ${DATA_STRUCTURES}/include
)

add_library(DataStructures-lib STATIC ${Srcs} ${Hdrs})
SET_TARGET_PROPERTIES(DataStructures-lib PROPERTIES LINKER_LANGUAGE CXX)
add_executable(testGraph ${GraphMainSrcs} ${Srcs} ${Hdrs})
add_executable(testTree ${TreeMainSrcs} ${Srcs} ${Hdrs})
include_directories(DataStructures-lib ${DATA_STRUCTURES}/include)
