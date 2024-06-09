#include <godot_cpp/variant/utility_functions.hpp>

#include "StreamReader.hpp"

#include "WorldChunk.hpp"

namespace SWBF2
{
    void WorldChunk::ProcessChunk(StreamReader &streamReader)
    {
        auto nameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();

        std::string worldName;
        *nameReaderChild >> worldName;

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChild()).has_value())
        {
            switch (readerChild->GetHeader().m_Magic)
            {
                case "TNAM"_m: {
                    std::string terrainName;
                    *readerChild >> terrainName;
                    break;
                }

                case "SNAM"_m: {
                    std::string skyName;
                    *readerChild >> skyName;
                    break;
                }

                default:
                    break;
            }
        }
    }
}
