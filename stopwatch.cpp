#include "stopwatch.h"

namespace {
using namespace jam;
using namespace std::chrono;
}

StopWatch::StopWatch() {
}

int StopWatch::asHours() const {
    return duration_cast<hours>(t_end - t_start).count();
}

int StopWatch::asMinutes() const {
    return duration_cast<minutes>(t_end - t_start).count();
}

int StopWatch::asSeconds() const {
    return duration_cast<seconds>(t_end - t_start).count();
}

int StopWatch::asMilliseconds() const {
    return duration_cast<milliseconds>(t_end - t_start).count();
}

int StopWatch::asMicroseconds() const {
    return duration_cast<microseconds>(t_end - t_start).count();
}

int StopWatch::asNanoseconds() const {
    return duration_cast<nanoseconds>(t_end - t_start).count();
}
