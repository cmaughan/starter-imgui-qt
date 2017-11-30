#pragma once

#include <chrono>
#include <date/date.h>

using TimeSpan = std::chrono::seconds;
using Days = std::chrono::duration<int, std::ratio<24 * 3600>>;
using DateTime = std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>;

struct TimeRange
{
    DateTime Item1;
    DateTime Item2;
    TimeSpan Duration() const { return TimeSpan(Item2.time_since_epoch() - Item1.time_since_epoch()); }
    bool InRange(const DateTime& val) const { return val.time_since_epoch() >= Item1.time_since_epoch() && val.time_since_epoch() <= Item2.time_since_epoch(); }
    std::string to_string() const
    {
        using namespace date;
        std::ostringstream str;
        str << Item1 << " - " << Item2;
        return str.str();
    }
};

const auto halfDay = std::chrono::seconds(date::days(1)).count() / 2;
const auto fullDay = std::chrono::seconds(date::days(1)).count();
