
#pragma once

#include "Native/D3D9/D3D9Types.hpp"

namespace SWBF2::Native::TextureUtils
{
    enum class TextureFormatType : std::uint32_t {
        T_2D = 1,
        T_CUBE,
        T_3D,
    };
}
