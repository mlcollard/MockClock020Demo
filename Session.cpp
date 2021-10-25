/*
    Session.cpp

    Example of dependency injection and mock objects.

    * Classes are implemented directly to focus on dependency
      injection and mock objects. In production code, all
      classes would be in separate .hpp and .cpp files.
    * The code uses the C library time.h (ctime). In production
      code, use std::chrono.
*/

#include <ctime>
#include <thread>
#include <chrono>
#include <cassert>
#include "SessionReport.hpp"

namespace {
    // Wrapper for C++ sleep as UNIX sleep()
    void sleep(int t) {
        std::this_thread::sleep_for(std::chrono::seconds(t));
    }
}

class Clock {
public:
    virtual std::time_t start() const = 0;
    virtual std::time_t now() const = 0;
};

class TimeClock : public Clock {
public:

    virtual std::time_t start() const {
        return now();
    }

    virtual std::time_t now() const {
        return std::time(nullptr);
    }
};

class Session {
public:
    // constructor
    Session(const Clock& clock = TimeClock())
        : clock(clock), start_time(clock.start())
    {}

    // stop the session
    void stop() {
        stop_time = clock.now();
    }

    // elapsed time in seconds of the stopped session
    std::time_t seconds() {
        return stop_time - start_time;
    }

private:
    const Clock& clock;
    std::time_t start_time;
    std::time_t stop_time;
};

int main() {

    // 2-second session
    {
        Session s;
        sleep(2);
        s.stop();
        assert(SessionReport::displayTime(s.seconds()) == "00:00:02");
    }

    return 0;
}
