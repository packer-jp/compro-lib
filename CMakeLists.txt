cmake_minimum_required(VERSION 3.16)
project(compro-lib)

set(CMAKE_CXX_STANDARD 14)

add_executable(Binary-Search-0 test/AOJ/ALDS1/Binary-Search-0.test.cpp utility/binary-search.hpp)
add_executable(String-Search-0 test/AOJ/ALDS1/String-Search-0.test.cpp string/rolling-hash.hpp)
add_executable(Pattern-Search-0 test/AOJ/ALDS1/Pattern-Search-0.test.cpp string/rolling-hash-2d.hpp)
add_executable(Prime-Numbers-0 test/AOJ/ALDS1/Prime-Numbers-0.test.cpp mathematics/get-prime-table.hpp)

add_executable(Convex-Hull-0 test/AOJ/CGL/Convex-Hull-0.test.cpp geometry/geometry.hpp)

add_executable(Range-Minimum-Query-0 test/AOJ/DSL/Range-Minimum-Query-0.test.cpp data-structure/segment-tree.hpp)
add_executable(Range-Sum-Query-0 test/AOJ/DSL/Range-Sum-Query-0.test.cpp data-structure/segment-tree.hpp)
add_executable(Range-Sum-Query-1 test/AOJ/DSL/Range-Sum-Query-1.test.cpp data-structure/fenwick-tree.hpp)
add_executable(Range-Add-Query-0 test/AOJ/DSL/Range-Add-Query-0.test.cpp data-structure/fenwick-tree.hpp)
add_executable(RMQ-and-RUQ-0 test/AOJ/DSL/RMQ-and-RUQ-0.test.cpp data-structure/lazy-segment-tree.hpp)
add_executable(RSQ-and-RAQ-0 test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp data-structure/lazy-segment-tree.hpp)
add_executable(RMQ-and-RAQ-0 test/AOJ/DSL/RMQ-and-RAQ-0.test.cpp data-structure/lazy-segment-tree.hpp)
add_executable(Vector-0 test/AOJ/ITP2/Vector-0.test.cpp data-structure/splay-tree.hpp)
add_executable(Vector-1 test/AOJ/ITP2/Vector-1.test.cpp data-structure/red-black-tree.hpp)

add_executable(Largest-Rectangle-in-a-Histogram-0 test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp utility/histogram-largest-rectangle.hpp)

add_executable(Single-Source-Shortest-Path-0 test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp graph/dijkstra.hpp)
add_executable(Single-Source-Shortest-Path-Negative-Edges-0 test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp graph/bellman-ford.hpp)
add_executable(All-Pairs-Shortest-Path-0 test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp graph/warshall-floyd.hpp)
add_executable(Diameter-of-a-Tree-0 test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp graph/re-rooting.hpp)
add_executable(Bipartite-Matching-0 test/AOJ/GRL/Bipartite-Matching-0.test.cpp graph/bipartite-matching.hpp)
add_executable(Maximum-Flow-0 test/AOJ/GRL/Maximum-Flow-0.test.cpp graph/ford-fulkerson.hpp)
add_executable(Maximum-Flow-1 test/AOJ/GRL/Maximum-Flow-1.test.cpp graph/dinic.hpp)
add_executable(Strongly-Connected-Components-0 test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp graph/strongly-connected-components.hpp)
add_executable(Bridges-0 test/AOJ/GRL/Bridges-0.test.cpp graph/low-link.hpp)
add_executable(Articulation-Points-0 test/AOJ/GRL/Articulation-Points-0.test.cpp graph/low-link.hpp)

add_executable(How-Many-Divisors-0 test/AOJ/ITP1/How-Many-Divisors-0.test.cpp mathematics/get-divisors.hpp)

add_executable(Power-0 test/AOJ/NTL/Power-0.test.cpp mathematics/mod-int.hpp)
add_executable(Prime-Factorize-0 test/AOJ/NTL/Prime-Factorize-0.test.cpp mathematics/prime-factorize.hpp)
add_executable(Prime-Factorize-1 test/AOJ/NTL/Prime-Factorize-1.test.cpp mathematics/multi-prime-factorize.hpp)

add_executable(RMQ-0 test/AOJ/Volume15/RMQ-0.test.cpp data-structure/splay-tree.hpp)
add_executable(RMQ-1 test/AOJ/Volume15/RMQ-1.test.cpp data-structure/red-black-tree.hpp)

add_executable(Tree-0 test/AOJ/Volume26/Tree-0.test.cpp graph/heavy-light-decomposition.hpp data-structure/lazy-segment-tree.hpp)

add_executable(Convolution-mod-1000000007-0 test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp mathematics/convolute.hpp mathematics/mod-int.hpp)

add_executable(Many-A-Plus-B-0 test/Library-Checker/Sample/Many-A-Plus-B-0.test.cpp utility/fast-io.hpp)


add_executable(heavy-light-decomposition test/unit-test/graph/heavy-light-decomposition.test.cpp graph/heavy-light-decomposition.hpp)
add_executable(topological-sort test/unit-test/graph/topological-sort.test.cpp graph/topological-sort.hpp)
add_executable(to-rooted-tree test/unit-test/graph/to-rooted-tree.test.cpp graph/to-rooted-tree.hpp)

add_executable(mod-int test/unit-test/mathematics/mod-int.test.cpp mathematics/mod-int.hpp)
add_executable(matrix test/unit-test/mathematics/matrix.test.cpp mathematics/matrix.hpp)
add_executable(permutation test/unit-test/mathematics/permutation.test.cpp mathematics/permutation.hpp)
add_executable(moebius test/unit-test/mathematics/moebius.test.cpp mathematics/moebius.hpp string/run-length-encoding.hpp)
add_executable(rational test/unit-test/mathematics/rational.test.cpp mathematics/rational.hpp)

add_executable(trie test/unit-test/string/trie.test.cpp)
add_executable(run-length-encoding test/unit-test/string/run-length-encoding.test.cpp string/run-length-encoding.hpp)