
#pragma once

#include "Native/D3D9/D3D9Types.hpp"

#include <godot_cpp/classes/image_texture.hpp>

namespace SWBF2::Native
{
    typedef struct _TEX_FMT_FACE_LVL
    {
        uint32_t m_mipLevel;
        uint32_t m_bodySize;
        std::vector<std::byte> m_imageInBytes;
    } TextureFormatFaceLevel;

    typedef struct _TEX_FMT
    {
        _TEX_FMT() = default;
        _TEX_FMT(_TEX_FMT &&) = default;
        _TEX_FMT(const _TEX_FMT &) = delete;

        D3DFORMAT m_format;
        uint16_t m_width;
        uint16_t m_height;
        uint16_t m_depth;
        uint16_t m_mipmapCount;
        uint32_t m_typeDetailBias;

        std::vector<TextureFormatFaceLevel> m_faceLevels;

        godot::Ref<godot::ImageTexture> m_gdImageTexture;
    } TextureFormat;

    class Texture {
    public:
        Texture() = default;
        Texture(const Texture &) = delete;
        Texture &operator=(const Texture &) = delete;

        std::string m_name;

        uint32_t m_formatCount;
        std::vector<D3DFORMAT> m_d3dFormats;

        std::vector<TextureFormat> m_formats;
    };
}
