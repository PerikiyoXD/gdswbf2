#pragma once

#include "StreamReader.hpp"

#include "../Model.hpp"

namespace SWBF2
{
    class ModelSegmentChunk {
    public:
        static void ProcessChunk(StreamReader &streamReader, Model &model);

        static void ProcessVerticesBuffer(StreamReader &streamReader, Model& model, ModelSegment &segment);
    };

}
