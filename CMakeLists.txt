cmake_minimum_required(VERSION 3.16)
project(compro-lib)

set(CMAKE_CXX_STANDARD 14)

add_executable(range-minimum-query-0 test/AOJ/DSL/range-minimum-query-0.test.cpp data-structure/segment-tree.hpp)
add_executable(range-sum-query-0 test/AOJ/DSL/range-sum-query-0.test.cpp data-structure/segment-tree.hpp)
add_executable(rmq-and-ruq-0 test/AOJ/DSL/rmq-and-ruq-0.test.cpp data-structure/lazy-segment-tree.hpp)
add_executable(rsq-and-raq-0 test/AOJ/DSL/rsq-and-raq-0.test.cpp data-structure/lazy-segment-tree.hpp)