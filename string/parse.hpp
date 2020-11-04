#include <iostream>
#include <string>

using state = std::string::const_iterator;
struct parse_error {};

void consume(state &begin, char expected) {
    if (*begin == expected) {
        begin++;
    } else {
        std::cerr << "Expected '" << expected << "' but got '" << *begin << "'" << std::endl;
        std::cerr << "Rest string is '";
        while (*begin) { std::cerr << *begin++; }
        std::cerr << "'" << std::endl;
        throw parse_error();
    }
}

struct parser {
    int number(state &begin) {
        int ret = 0;
        while (isdigit(*begin)) {
            ret *= 10;
            ret += *begin - '0';
            begin++;
        }
        return ret;
    }
    int term(state &begin) {
        int ret = factor(begin);
        while (true) {
            if (*begin == '*') {
                consume(begin, '*');
                ret *= factor(begin);
            } else if (*begin == '/') {
                consume(begin, '/');
                ret /= factor(begin);
            } else {
                break;
            }
        }
        return ret;
    }
    int expr(state &begin) {
        int ret = term(begin);
        while (true) {
            if (*begin == '+') {
                consume(begin, '+');
                ret += term(begin);
            } else if (*begin == '-') {
                consume(begin, '-');
                ret -= term(begin);
            } else {
                break;
            }
        }
        return ret;
    }
    int factor(state &begin) {
        if (*begin == '(') {
            consume(begin, '(');
            int ret = expr(begin);
            consume(begin, ')');
            return ret;
        } else {
            return number(begin);
        }
    }
};