#pragma once

#include "Types.hpp"

namespace SWBF2::Native
{
    enum class MaterialFlags : uint32_t {
        Normal = 1,
        Hardedged = 2,
        Transparent = 4,
        Glossmap = 8,
        Glow = 16,
        BumpMap = 32,
        Additive = 64,
        Specular = 128,
        EnvMap = 256,
        VertexLighting = 512,
        TiledNormalmap = 2048,
        Doublesided = 65536,

        Scrolling = 16777216,
        Energy = 33554432,
        Animated = 67108864,

        AttachedLight = 134217728,
    };

    class Material {
    public:
        MaterialFlags m_flags;
        godot::Color m_diffuseColor;
        godot::Color m_specularColor;
        uint32_t m_specularExponent;
        uint32_t m_parameters[2];
        std::string m_attachedLight;
    };
}
