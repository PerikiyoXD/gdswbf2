#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Level.hpp"

#include "StreamReader.hpp"

#include "WorldChunk.hpp"

#include "Native/Level.hpp"

namespace SWBF2::Native
{
    void WorldChunk::ProcessChunk(StreamReader &streamReader)
    {
        auto nameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();

        *nameReaderChild >> Level::m_world.m_worldName;

        std::optional<StreamReader> readerChild;
        while ((readerChild = streamReader.ReadChild()).has_value())
        {
            switch (readerChild->GetHeader().m_Magic)
            {
                case "TNAM"_m: {
                    *readerChild >> Level::m_world.m_terrainName;
                    break;
                }

                case "SNAM"_m: {
                    *readerChild >> Level::m_world.m_skyName;
                    break;
                }

                default:
                    break;
            }
        }
    }
}
