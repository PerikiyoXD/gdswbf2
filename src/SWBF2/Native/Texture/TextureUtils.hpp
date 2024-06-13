
#pragma once

#include <DirectXTex.h>

#include "Native/D3D9/D3D9Types.hpp"

namespace SWBF2::Native::TextureUtils
{
    enum class TextureFormatType : std::uint32_t {
        T_2D = 1,
        T_CUBE,
        T_3D,
    };

    DirectX::ScratchImage CreateScratchImage(TextureFormatType textureType, uint32_t width, uint32_t height, std::size_t depth, D3DFORMAT format, uint32_t mipLevel);

    inline DXGI_FORMAT D3DToDXDGIFormat(const Native::D3DFORMAT format)
    {
        switch (format) {
            case Native::D3DFMT_A8R8G8B8:
                return DXGI_FORMAT_B8G8R8A8_UNORM;
            case Native::D3DFMT_X8R8G8B8:
                return DXGI_FORMAT_B8G8R8X8_UNORM;
            case Native::D3DFMT_R5G6B5:
                return DXGI_FORMAT_B5G6R5_UNORM;
            case Native::D3DFMT_A1R5G5B5:
            case Native::D3DFMT_X1R5G5B5:
                return DXGI_FORMAT_B5G5R5A1_UNORM;
            case Native::D3DFMT_A4R4G4B4:
                return DXGI_FORMAT_B4G4R4A4_UNORM;
            case Native::D3DFMT_A8:
                return DXGI_FORMAT_A8_UNORM;
            case Native::D3DFMT_A2B10G10R10:
                return DXGI_FORMAT_R10G10B10A2_UNORM;
            case Native::D3DFMT_A8B8G8R8:
                return DXGI_FORMAT_R8G8B8A8_UNORM;
            case Native::D3DFMT_G16R16:
                return DXGI_FORMAT_R16G16_UNORM;
            case Native::D3DFMT_A16B16G16R16:
                return DXGI_FORMAT_R16G16B16A16_UNORM;
            case Native::D3DFMT_V8U8:
                return DXGI_FORMAT_R8G8_SNORM;
            case Native::D3DFMT_Q8W8V8U8:
                return DXGI_FORMAT_R8G8B8A8_SNORM;
            case Native::D3DFMT_V16U16:
                return DXGI_FORMAT_R16G16_SNORM;
            case Native::D3DFMT_R8G8_B8G8:
                return DXGI_FORMAT_G8R8_G8B8_UNORM;
            case Native::D3DFMT_G8R8_G8B8:
                return DXGI_FORMAT_R8G8_B8G8_UNORM;
            case Native::D3DFMT_DXT1:
                return DXGI_FORMAT_BC1_UNORM;
            case Native::D3DFMT_DXT2:
            case Native::D3DFMT_DXT3:
                return DXGI_FORMAT_BC2_UNORM;
            case Native::D3DFMT_DXT4:
            case Native::D3DFMT_DXT5:
                return DXGI_FORMAT_BC3_UNORM;
            case Native::D3DFMT_D16_LOCKABLE:
            case Native::D3DFMT_D16:
                return DXGI_FORMAT_D16_UNORM;
            case Native::D3DFMT_D24S8:
                return DXGI_FORMAT_D24_UNORM_S8_UINT;
            case Native::D3DFMT_D32:
            case Native::D3DFMT_D32F_LOCKABLE:
                return DXGI_FORMAT_D32_FLOAT;
            case Native::D3DFMT_Q16W16V16U16:
                return DXGI_FORMAT_R16G16B16A16_SNORM;
            case Native::D3DFMT_R16F:
                return DXGI_FORMAT_R16_FLOAT;
            case Native::D3DFMT_G16R16F:
                return DXGI_FORMAT_R16G16_FLOAT;
            case Native::D3DFMT_A16B16G16R16F:
                return DXGI_FORMAT_R16G16B16A16_FLOAT;
            case Native::D3DFMT_R32F:
                return DXGI_FORMAT_R32_FLOAT;
            case Native::D3DFMT_G32R32F:
                return DXGI_FORMAT_R32G32_FLOAT;
            case Native::D3DFMT_A32B32G32R32F:
                return DXGI_FORMAT_R32G32B32A32_FLOAT;
            case Native::D3DFMT_A2B10G10R10_XR_BIAS:
                return DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM;
            case Native::D3DFMT_L8:
                return DXGI_FORMAT_R8_UNORM;
            case Native::D3DFMT_A8L8:
                return DXGI_FORMAT_R8G8_UNORM;
            case Native::D3DFMT_L16:
                return DXGI_FORMAT_R16_UNORM;
            default:
                throw std::runtime_error{ "Texture has unknown or unsupported format." };
        }
    }
}
