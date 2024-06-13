#include <godot_cpp/variant/utility_functions.hpp>

#include "Native/Chunks/StreamReader.hpp"
#include "Native/Chunks/TextureChunk.hpp"

#include "Native/Texture/TextureUtils.hpp"
#include "Native/Level.hpp"

namespace SWBF2::Native
{
    void TextureChunk::ProcessChunk(StreamReader &streamReader)
    {
        std::unique_ptr<Texture> tex = std::make_unique<Texture>();

        auto texNameReaderChild = streamReader.ReadChildWithHeader<"NAME"_m>();

        *texNameReaderChild >> tex->m_name;

        auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();

        *infoReaderChild >> tex->m_formatCount;

        tex->m_d3dFormats.resize(tex->m_formatCount);
        *infoReaderChild >> tex->m_d3dFormats;

        std::optional<StreamReader> fmtReaderChild;
        while ((fmtReaderChild = streamReader.ReadChild()).has_value())
        {
            switch (fmtReaderChild->GetHeader().m_Magic)
            {
                case "FMT_"_m: {
                    StreamReader r{ *fmtReaderChild };
                    TextureChunk::ProcessFMTChunk(r, tex.get());
                    break;
                }

                default:
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": ", fmtReaderChild->GetHeader().ToString().c_str(), " not implemented");
                    break;
            }
        }

        Level::m_tex.try_emplace(tex->m_name, std::move(tex));
    }

    void TextureChunk::ProcessFMTChunk(StreamReader &streamReader, Texture *tex)
    {
        auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();

        auto &fmt = tex->m_formats.emplace_back(TextureFormat());
        *infoReaderChild >> fmt.m_format;
        *infoReaderChild >> fmt.m_width;
        *infoReaderChild >> fmt.m_height;
        *infoReaderChild >> fmt.m_depth;
        *infoReaderChild >> fmt.m_mipmapCount;
        *infoReaderChild >> fmt.m_typeDetailBias;

        auto faceReaderChild = streamReader.ReadChildWithHeader<"FACE"_m>();

        std::optional<StreamReader> lvlReaderChild;
        while ((lvlReaderChild = faceReaderChild->ReadChild()).has_value())
        {
            switch (lvlReaderChild->GetHeader().m_Magic)
            {
                case "LVL_"_m: {
                    StreamReader r{ *lvlReaderChild };
                    TextureChunk::ProcessTextureLevelChunk(r, fmt);
                    break;
                }

                default:
                    godot::UtilityFunctions::printerr(__FILE__, ":", __LINE__, ": ", lvlReaderChild->GetHeader().ToString().c_str(), " not implemented");
                    break;
            }
        }
    }

    void TextureChunk::ProcessTextureLevelChunk(StreamReader &streamReader, TextureFormat &fmt)
    {
        TextureFormatFaceLevel lvl;

        auto infoReaderChild = streamReader.ReadChildWithHeader<"INFO"_m>();

        *infoReaderChild >> lvl.m_mipLevel;
        *infoReaderChild >> lvl.m_bodySize;

        auto bodyReaderChild = streamReader.ReadChildWithHeader<"BODY"_m>();

        lvl.m_imageInBytes.resize(lvl.m_bodySize);
        *bodyReaderChild >> lvl.m_imageInBytes;

        fmt.m_faceLevels.push_back(lvl);
    }
}
