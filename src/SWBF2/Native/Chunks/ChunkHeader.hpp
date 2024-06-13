#pragma once

#include "Types.hpp"

namespace SWBF2::Native
{
    struct ChunkHeader
    {
        union
        {
            uint32_t m_Magic = 0;
            char m_Name[4];
        };

        uint32_t size = 0;

        std::string ToString() const;
        bool operator==(const ChunkHeader &other) const;
        bool operator!=(const ChunkHeader &other) const;

        // the following mainly exist to meet std::set's expectations
        bool operator<(const ChunkHeader &other) const;
        bool operator>(const ChunkHeader &other) const;
    };

    _FORCE_INLINE_ const ChunkHeader operator""_h(const char *chars, const size_t length)
    {
        return *reinterpret_cast<const ChunkHeader *>(chars);
    }

    constexpr uint32_t operator""_m(const char *chars, const size_t length)
    {
        uint32_t result = 0;
        result |= chars[0] << 0;
        result |= chars[1] << 8;
        result |= chars[2] << 16;
        result |= chars[3] << 24;
        return result;
    }

    bool IsPrintableHeader(const ChunkHeader &hedr);
    bool IsKnownHeader(const ChunkHeader &hedr);
}
