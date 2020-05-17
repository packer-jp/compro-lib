cmake_minimum_required(VERSION 3.16)
project(compro-lib)

set(CMAKE_CXX_STANDARD 14)

add_executable(Binary-Search-0 test/AOJ/ALDS1/Binary-Search-0.test.cpp utility/binary-search.hpp)
add_executable(String-Search-0 test/AOJ/ALDS1/String-Search-0.test.cpp string/rolling-hash.hpp)
add_executable(Prime-Numbers-0 test/AOJ/ALDS1/Prime-Numbers-0.test.cpp mathematics/get-prime-table.hpp)

add_executable(Range-Minimum-Query-0 test/AOJ/DSL/Range-Minimum-Query-0.test.cpp data-structure/segment-tree.hpp)
add_executable(Range-Sum-Query-0 test/AOJ/DSL/Range-Sum-Query-0.test.cpp data-structure/segment-tree.hpp)
add_executable(Range-Sum-Query-1 test/AOJ/DSL/Range-Sum-Query-1.test.cpp data-structure/fenwick-tree.hpp)
add_executable(Range-Add-Query-0 test/AOJ/DSL/Range-Add-Query-0.test.cpp data-structure/fenwick-tree.hpp)
add_executable(RMQ-and-RUQ-0 test/AOJ/DSL/RMQ-and-RUQ-0.test.cpp data-structure/lazy-segment-tree.hpp)
add_executable(RSQ-and-RAQ-0 test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp data-structure/lazy-segment-tree.hpp)

add_executable(Single-Source-Shortest-Path-0 test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp graph/dijkstra.hpp)
add_executable(Single-Source-Shortest-Path-Negative-Edges-0 test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp graph/bellman-ford.hpp)
add_executable(All-Pairs-Shortest-Path-0 test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp graph/warshall-floyd.hpp)
add_executable(Diameter-of-a-Tree-0 test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp graph/re-rooting.hpp)

add_executable(How-Many-Divisors-0 test/AOJ/ITP1/How-Many-Divisors-0.test.cpp mathematics/get-divisors.hpp)

add_executable(Power-0 test/AOJ/NTL/Power-0.test.cpp mathematics/mod-int.hpp)
add_executable(Prime-Factorize-0 test/AOJ/NTL/Prime-Factorize-0.test.cpp mathematics/get-prime-factors.hpp)

add_executable(Tree-0 test/AOJ/Volume26/Tree-0.test.cpp graph/heavy-light-decomposition.hpp data-structure/lazy-segment-tree.hpp)

add_executable(Convolution-mod-1000000007-0 test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp mathematics/convolute.hpp mathematics/mod-int.hpp)

add_executable(heavy-light-decomposition test/unit-test/graph/heavy-light-decomposition.test.cpp graph/heavy-light-decomposition.hpp)

add_executable(mod-int test/unit-test/mathematics/mod-int.test.cpp mathematics/mod-int.hpp)
add_executable(matrix test/unit-test/mathematics/matrix.test.cpp mathematics/matrix.hpp)
add_executable(permutation test/unit-test/mathematics/permutation.test.cpp mathematics/permutation.hpp)