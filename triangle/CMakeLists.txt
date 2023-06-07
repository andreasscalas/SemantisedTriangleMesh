cmake_minimum_required(VERSION 2.8.8)

project(Triangle)

set( Srcs
    ${TRIANGLE}/shewchuk_triangle.cpp
    ${TRIANGLE}/trianglehelper.cpp
)
set( Hdrs
    ${TRIANGLE}/shewchuk_triangle.hpp
    ${TRIANGLE}/trianglehelper.hpp
)

add_definitions(-DTRILIBRARY -DANSI_DECLARATORS -DVOID=void -DREAL=double -DNO_TIMER=true)
add_library(${PROJECT_NAME}-lib ${Srcs} ${Hdrs})
target_include_directories(${PROJECT_NAME}-lib PUBLIC $<BUILD_INTERFACE:${TRIANGLE}/>)
