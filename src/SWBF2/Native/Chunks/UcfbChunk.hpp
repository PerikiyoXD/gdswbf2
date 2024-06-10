#pragma once

#include "ChunkHeader.hpp"

namespace SWBF2::Native
{
    class UcfbChunk {
    public:
        using ChunkProcessingFunction = std::function<void(StreamReader &streamReader)>;

        static inline const std::unordered_map<uint32_t, ChunkProcessingFunction> m_functions{};

        static void ReadUcfbFile(const std::string &filename);
        static void ProcessChunk(StreamReader &streamReader);
    };
}
