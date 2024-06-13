#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <string_view>
#include <functional>
#include <vector>
#include <optional>
#include <stdexcept>
#include <set>
#include <array>
#include <map>
#include <format>

#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/variant/vector3i.hpp>

namespace SWBF2
{
    typedef uint32_t ChunkSize;

    typedef uint16_t SWBF2Handle;

    constexpr auto SWBF2HANDLE_INVALID = 0xffff;

    enum class Topology : uint32_t {
        Unknown,
        PointList,
        LineList,
        LineStrip,
        TriangleList,
        TriangleStrip,
        TriangleFan,
    };
}
