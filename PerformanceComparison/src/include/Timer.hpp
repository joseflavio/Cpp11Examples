#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <stdafx.h>

#include <sstream>

class Timer {

private:
    clock_t clock_t0;
    time_t time_t0;

public:
    Timer() : clock_t0(clock()), time_t0(time(0)) {
    }

    static std::string Elapsed(const Timer& t0) {
        Timer t1;
        return Elapsed(t0, t1);
    }

    static std::string Elapsed(const Timer& t0, const Timer& t1) {
        long int time_elapsed = t1.time_t0-t0.time_t0;
        double clock_elapsed = ((double) (t1.clock_t0 - t0.clock_t0)) / CLOCKS_PER_SEC;
        std::stringstream ss;
        ss << time_elapsed << " time_secs / " << clock_elapsed << " cpu_secs";
        return ss.str();
    }

};


#endif /* TIMER_HPP_ */
