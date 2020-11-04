#include <iostream>
#include <string>

using state = std::string::const_iterator;
struct parse_error {};

void consume(state &cur, char expected) {
    if (*cur == expected) {
        cur++;
    } else {
        std::cerr << "Expected '" << expected << "' but got '" << *cur << "'" << std::endl;
        std::cerr << "Rest string is '";
        while (*cur) { std::cerr << *cur++; }
        std::cerr << "'" << std::endl;
        throw parse_error();
    }
}


struct parser {
    int expr(state &cur) {
        int ret = term(cur);
        while (true) {
            if (*cur == '+') {
                consume(cur, '+');
                ret += term(cur);
            } else if (*cur == '-') {
                consume(cur, '-');
                ret -= term(cur);
            } else {
                break;
            }
        }
        return ret;
    }
    int term(state &cur) {
        int ret = factor(cur);
        while (true) {
            if (*cur == '*') {
                consume(cur, '*');
                ret *= factor(cur);
            } else if (*cur == '/') {
                consume(cur, '/');
                ret /= factor(cur);
            } else {
                break;
            }
        }
        return ret;
    }
    int factor(state &cur) {
        if (*cur == '(') {
            consume(cur, '(');
            int ret = expr(cur);
            consume(cur, ')');
            return ret;
        } else {
            return number(cur);
        }
    }
    int number(state &cur) {
        int ret = 0;
        while (isdigit(*cur)) {
            ret *= 10;
            ret += *cur - '0';
            cur++;
        }
        return ret;
    }
};