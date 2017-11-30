#pragma once

#include <string>
#include "string/stringutils.h"

using decimal = double;

inline decimal PriceStringToDecimal(const std::string& strVal)
{
    auto convert = StringUtils::ReplaceString(strVal, ",", "");
    if (strVal.empty())
        return 0.0;
    return std::stod(convert);
}

inline int32_t PriceStringToInt32(const std::string& strVal)
{
    auto convert = StringUtils::ReplaceString(strVal, ",", "");
    if (strVal.empty())
        return 0;
    return std::stoi(convert);
}
