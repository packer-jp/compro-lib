#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../mathematics/matrix.hpp"
#include"../../../mathematics/mod-int.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    using mint = mod_int<>;
    struct mint_mat {
        using T = mint;
        static T plus(const T &a, const T &b) { return a + b; }
        static T cross(const T &a, const T &b) { return a * b; }
        static T id_plus() { return 0; }
        static T id_cross() { return 1; }
        static T inv_plus(const T &a) { return -a; }
        static T inv_cross(const T &a) { return a.inv(); }
        static T eps() { return 0; };
        static bool less_abs(const T &a, const T &b) { return a.val < b.val; };
    };
    using mat = matrix<mint_mat>;
    mat A({{8, 2, 3, 2},
           {1, 3, 2, 7},
           {2, 5, 7, 6},
           {1, 9, 9, 4}});
    mat A2({{74, 55, 67, 56},
            {22, 84, 86, 63},
            {41, 108, 119, 105},
            {39, 110, 120, 135}});
    assert(A * A == A2);
    assert(A * A * A * A * A * A * A * A * A * A == A.pow(10));
    assert(A / A == mat::identity(A.height()));
    assert(A.pow(12) / A.pow(2) / A.pow(3) / A.pow(5) == A * A);
    assert(-A == mat(A.height(), A.width()) - A);
    cout << "Hello World" << endl;
}