#pragma once

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Models/Model.hpp"

namespace SWBF2::Native
{
    class ModelSegmentChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader, Model &model);

        static void ProcessVerticesBuffer(StreamReader &streamReader, Model &model, ModelSegment &segment);
    };

}
