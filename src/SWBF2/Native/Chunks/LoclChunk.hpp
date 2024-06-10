#pragma once

#include "ChunkHeader.hpp"

namespace SWBF2::Native
{
    class LoclChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
        static void ReadLoclEntries(StreamReader &streamReader, const std::string &loclName);
    };
}
