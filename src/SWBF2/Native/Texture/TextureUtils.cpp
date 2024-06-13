
#include "TextureUtils.hpp"

namespace SWBF2::Native::TextureUtils
{
    DirectX::ScratchImage CreateScratchImage(TextureFormatType textureType, uint32_t width, uint32_t height, std::size_t depth, D3DFORMAT format, uint32_t mipLevel)
    {
        DirectX::ScratchImage image;
        switch (textureType)
        {
            case TextureFormatType::T_2D:
                if (image.Initialize2D(D3DToDXDGIFormat(format), width, height, 1, mipLevel) != 0)
                    throw std::runtime_error("failed to initialize 2D image");
                break;
            case TextureFormatType::T_CUBE:
                if (image.InitializeCube(D3DToDXDGIFormat(format), width, height, 1, mipLevel) != 0)
                    throw std::runtime_error("failed to initialize 2D image");
                break;
            case TextureFormatType::T_3D:
                if (image.Initialize2D(D3DToDXDGIFormat(format), width, height, depth, mipLevel) != 0)
                    throw std::runtime_error("failed to initialize 2D image");
                break;
        }

        return image;
    }
}
