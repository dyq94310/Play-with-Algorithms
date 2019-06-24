cmake_minimum_required(VERSION 3.14)
project(UnionFind)

set(CMAKE_CXX_STANDARD 14)

add_executable(UnionFind main.cpp QuickFind.h UnionFindTestHelper.h QuickUnion.h)