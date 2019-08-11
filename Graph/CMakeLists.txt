cmake_minimum_required(VERSION 3.14)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graph main.cpp DenseGraph.h SparseGraph.h)