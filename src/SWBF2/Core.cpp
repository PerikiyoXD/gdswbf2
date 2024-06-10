
#include <godot_cpp/variant/utility_functions.hpp>

#include "Core.hpp"
#include "Version.h"

#include "Native/Chunks/ChunkProcessor.hpp"
#include "Native/Level.hpp"

#include <chrono>
#include <iostream>
#include <thread>

namespace SWBF2
{
    Core::Core()
    {
    }

    void Core::_ready()
    {
        godot::UtilityFunctions::print("hello world!");

        // UcfbChunk::ReadUcfbFile("data/_lvl_pc/common.lvl");
        // UcfbChunk::ReadUcfbFile("data/_lvl_pc/core.lvl");
        SWBF2::Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/cor/cor1.lvl");
    }

    void Core::_bind_methods()
    {
    }
}
