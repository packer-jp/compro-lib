cmake_minimum_required(VERSION 3.16)
project(compro-lib)

set(CMAKE_CXX_STANDARD 14)

add_executable(Range-Minimum-Query-0 test/AOJ/DSL/Range-Minimum-Query-0.test.cpp data-structure/segment-tree.hpp)
add_executable(Range-Sum-Query-0 test/AOJ/DSL/Range-Sum-Query-0.test.cpp data-structure/segment-tree.hpp)
add_executable(RMQ-and-RUQ-0 test/AOJ/DSL/RMQ-and-RUQ-0.test.cpp data-structure/lazy-segment-tree.hpp)
add_executable(RSQ-and-RAQ-0 test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp data-structure/lazy-segment-tree.hpp)
add_executable(Convolution-mod-1000000007-0 test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp mathematics/convolution.hpp mathematics/mod-int.hpp)
add_executable(mod-int-0 test/unit-test/mathematics/mod-int.test.cpp mathematics/mod-int.hpp)