#pragma once

#include "StreamReader.hpp"

namespace SWBF2
{
    class WorldChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
    };

}
