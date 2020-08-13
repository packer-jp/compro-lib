/*
 * @title タイマー
 * @docs docs/utility/timer.md
 */

struct timer {
    unsigned long long begin_cycle;
    double cycle_per_sec = 2.8e9;
    unsigned long long get_cycle() {
        unsigned low, high;
        __asm__ volatile("rdtsc":"=a"(low), "=d"(high));
        return ((unsigned long long) low) | ((unsigned long long) high << 32);
    }
    double get_time() { return (get_cycle() - begin_cycle) / cycle_per_sec; }
    void init() { begin_cycle = get_cycle(); }
} timer;