#include <iostream>

struct fast_io {
    static constexpr int size_in = 1 << 26, size_out = 1 << 26;
    char data_in[size_in], data_out[size_out], *p_in, *p_out, s[30];
    fast_io() { fread(data_in, 1, size_in, stdin), p_in = data_in, p_out = data_out; }
    ~fast_io() { fwrite(data_out, 1, p_out - data_out, stdout); }
    void putchar(char x) { *p_out++ = x; }
    template<typename T> void putint(T x) {
        if (x < 0) { *p_out++ = '-', x = -x; }
        int i = 0;
        do { s[i++] = x % 10 + '0'; } while (x /= 10);
        while (i--) { *p_out++ = s[i]; }
    }
    template<typename T=int> T getint() {
        while (!isdigit(*p_in) && *p_in != '-') { p_in++; }
        bool negative = *p_in == '-';
        T ret = negative ? 0 : *p_in - '0';
        while (isdigit(*++p_in)) { (ret *= 10) += *p_in - '0'; };
        return negative ? -ret : ret;
    }
} io;