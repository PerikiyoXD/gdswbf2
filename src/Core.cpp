
#include <godot_cpp/variant/utility_functions.hpp>

#include "Core.hpp"
#include "Version.h"

#include "SWBF2/Chunks/ChunkProcessor.hpp"

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
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(5000ms);

        godot::UtilityFunctions::print("hello world!");

        // UcfbChunk::ReadUcfbFile("data/_lvl_pc/common.lvl");
        // UcfbChunk::ReadUcfbFile("data/_lvl_pc/core.lvl");
        UcfbChunk::ReadUcfbFile("data/_lvl_pc/cor/cor1.lvl");
    }

    void Core::_bind_methods()
    {
    }
}
