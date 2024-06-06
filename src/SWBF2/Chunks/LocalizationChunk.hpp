#pragma once

namespace SWBF2
{
    class LocalizationChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader, StreamReader &parentReader);
    };

}
