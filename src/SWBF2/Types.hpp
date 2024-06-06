// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <string_view>
#include <functional>

namespace SWBF2
{
    typedef uint32_t ChunkSize;

    typedef uint32_t CRCChecksum;
    typedef uint32_t FNVHash;

    typedef uint16_t SWBF2Handle;

    constexpr auto SWBF2HANDLE_INVALID = 0xffff;

    namespace Wrappers
    {
        class MapsWrapper
        {
        public:
            std::unordered_map<FNVHash, size_t> LocalizationNameToIndex;
        };
    }
}
