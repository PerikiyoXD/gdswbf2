
#include <optional>

#include <godot_cpp/variant/utility_functions.hpp>

#include "ChunkHeader.hpp"
#include "StreamReader.hpp"

namespace SWBF2
{
    StreamReader::StreamReader()
    {
        m_head = 0;
        m_data = nullptr;
        m_header = { 0 };
    }

    StreamReader::StreamReader(const ChunkHeader &header, const std::byte *bytes)
        : m_header(header),
        m_data(bytes),
        m_head(0)
    {
    }

    StreamReader::StreamReader(const std::vector<std::byte> &bytes)
    {
        m_head = 0;
        m_data = bytes.data();

        m_header = reinterpret_cast<const ChunkHeader &>(m_data[0]);

        m_data = m_data + sizeof(ChunkHeader);
    }

    std::optional<StreamReader> StreamReader::ReadChild()
    {
        if (IsEof() || (m_head + sizeof(ChunkHeader)) >= m_header.size) {
            return std::nullopt;
        }

        ChunkHeader child;
        this->operator>>(child);

        auto prev_head = m_head;
        m_head += child.size;

        AlignHead();

        return StreamReader(child, m_data + prev_head);
    }

    bool StreamReader::SkipBytes(uint32_t bytes)
    {
        if (IsEof())
        {
            return false;
        }

        m_head += bytes;
        return true;
    }

    const ChunkHeader &StreamReader::GetHeader() const
    {
        return m_header;
    }

    std::size_t StreamReader::GetHead()
    {
        return m_head;
    }

    bool StreamReader::IsEof()
    {
        return m_head >= GetHeader().size;
    }

    void StreamReader::AlignHead()
    {
        const auto remainder = m_head % 4;
        if (remainder != 0) m_head += (4 - remainder);
    }
}
