/*
    SessionReport.cpp

    Format and output of a Session report.
*/

#include "SessionReport.hpp"
#include <sstream>
#include <iomanip>

// display the time
std::string SessionReport::displayTime(std::time_t totalSeconds) {

    int total = static_cast<int>(totalSeconds);
    int hours = total / (60 * 60);
    total %= 60 * 60;
    int minutes = total / 60;
    total %= 60;
    int seconds = total;

    std::ostringstream time;
    time << std::setw(2) << std::setfill('0') << hours
         << ":" << std::setw(2) << std::setfill('0') << minutes
         << ":" << std::setw(2) << std::setfill('0') << seconds;

    return time.str();
}
