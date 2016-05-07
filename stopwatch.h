#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

namespace jam {
class StopWatch {
public:
    StopWatch();

    int asHours() const;
    int asMinutes() const;
    int asSeconds() const;
    int asMilliseconds() const;
    int asMicroseconds() const;
    int asNanoseconds() const;

    inline void start() { t_start = std::chrono::steady_clock::now(); }
    inline void measure() { t_end = std::chrono::steady_clock::now(); }

private:
    std::chrono::steady_clock::time_point t_start;
    std::chrono::steady_clock::time_point t_end;
};
}

#endif  // STOPWATCH_H
