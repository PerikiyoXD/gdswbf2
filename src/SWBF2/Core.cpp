
#include <godot_cpp/variant/utility_functions.hpp>

#include "Core.hpp"
#include "Level.hpp"
#include "Version.h"

#include "Native/Chunks/ChunkProcessor.hpp"
#include "Native/API/ScriptingAPI.hpp"

#include <chrono>
#include <iostream>
#include <thread>
#include <filesystem>

namespace SWBF2
{
    Core::Core()
    {
    }

    void Core::_ready()
    {
        godot::UtilityFunctions::print("hello world!");

        // Find all the .lvl files under data/_lvl_pc and its subdirectories

        SWBF2::Native::API::ScriptingAPI::Register();

        {
            std::string path{ "data/_lvl_pc" };
            std::string ext{ ".lvl" };

            for (const auto &entry : std::filesystem::recursive_directory_iterator(path))
            {
                if (entry.is_regular_file() && entry.path().extension() == ext)
                {
                    godot::UtilityFunctions::print(entry.path().string().c_str());
                }
            }
        }


        // SWBF2::Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/common.lvl");
        // SWBF2::Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/core.lvl");
        
        try
        {
            add_child(memnew(Level));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void Core::_bind_methods()
    {
    }
}
