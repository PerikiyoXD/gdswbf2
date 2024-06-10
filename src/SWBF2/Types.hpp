// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <string_view>
#include <functional>
#include <vector>
#include <optional>
#include <stdexcept>

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "RGBA.hpp"

namespace SWBF2
{
    typedef uint32_t ChunkSize;

    typedef uint32_t CRCChecksum;
    typedef uint32_t FNVHash;

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
