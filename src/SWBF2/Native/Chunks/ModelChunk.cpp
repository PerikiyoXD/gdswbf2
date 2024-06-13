#include "ModelChunk.hpp"
#include "ModelSegmentChunk.hpp"
#include "StreamReader.hpp"

#include "Native/Level.hpp"
#include "Native/Models/Model.hpp"
#include "Native/Models/ModelSegment.hpp"

namespace SWBF2::Native
{
    void ModelChunk::ProcessChunk(StreamReader &streamReader)
    {
        Model model;

        auto modelNameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();

        *modelNameReaderChild >> model.m_name;

        auto vertexReaderChild = streamReader.ReadChildWithHeader<"VRTX"_m>();

        std::vector<std::byte> vertex;
        vertex.resize(vertexReaderChild->GetHeader().size);

        *vertexReaderChild >> vertex;

        auto nodeReaderChild = streamReader.ReadChildWithHeader<"NODE"_m>();

        *nodeReaderChild >> model.m_node;

        auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();

        *infoReaderChild >> model.m_info;

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChild()).has_value())
        {
            switch (readerChild->GetHeader().m_Magic)
            {
                case "segm"_m: {
                    StreamReader r{ *readerChild };
                    ModelSegmentChunk::ProcessChunk(r, model);
                    break;
                }

                case "SPHR"_m:
                default:
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": ", readerChild->GetHeader().ToString().c_str(), " not implemented");
                    break;
            }
        }

        Level::m_models.insert_or_assign(model.m_name, model);
    }
}
