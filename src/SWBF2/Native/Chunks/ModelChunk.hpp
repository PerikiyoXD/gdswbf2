#pragma once

#include "StreamReader.hpp"

namespace SWBF2::Native
{
    class ModelChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader);
    };

}
