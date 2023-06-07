cmake_minimum_required(VERSION 2.8)
project(KDTree CXX)


add_library(KDTree-lib KDTree.hpp KDTree.cpp)
target_include_directories(KDTree-lib PUBLIC $<BUILD_INTERFACE:${KDTREE}/>)
