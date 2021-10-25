/*
    SessionReport.hpp

    Format and output of a Session report.
*/

#ifndef INCLUDED_SESSIONREPORT_HPP
#define INCLUDED_SESSIONREPORT_HPP

#include <string>
#include <ctime>

class SessionReport {
public:

    // display the time
    static std::string displayTime(std::time_t seconds);

};

#endif
