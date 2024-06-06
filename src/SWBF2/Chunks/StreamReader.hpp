#pragma once

#include <vector>
#include <optional>

#include <godot_cpp/variant/utility_functions.hpp>

#include "ChunkHeader.hpp"

namespace SWBF2
{
    class StreamReader {

        ChunkHeader m_header;

        const std::byte *m_data;
        std::size_t m_head;

    public:
        StreamReader();
        StreamReader(const ChunkHeader &header, const std::byte *bytes);
        StreamReader(const std::vector<std::byte> &bytes);

        std::optional<StreamReader> ReadChild();
        bool SkipBytes(uint32_t bytes);
        const ChunkHeader &GetHeader() const;
        std::size_t GetHead();
        bool IsEof();
        void AlignHead();

        template<typename T>
        StreamReader &operator>>(T &value)
        {
            if (IsEof() || (m_head + sizeof(T)) >= m_header.size) {
                godot::UtilityFunctions::printerr(__LINE__, " - ", __FILE__, ": eof");
                return *this;
            }

            std::memcpy(&value, &m_data[m_head], sizeof(T));

            m_head += sizeof(T);

            return *this;
        }
    };
}
