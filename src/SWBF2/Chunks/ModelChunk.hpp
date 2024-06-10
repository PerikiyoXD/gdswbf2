#pragma once

#include "StreamReader.hpp"

namespace SWBF2
{
    class ModelChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
    };

}
