#pragma once

#include <algorithm>
#include <string>

namespace SWBF2
{
    inline void string_tolower(std::string &str)
    {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
    }
}
