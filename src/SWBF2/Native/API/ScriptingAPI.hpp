#pragma once

#include <sol/sol.hpp>

namespace SWBF2
{
    namespace Native
    {
        namespace API
        {
            class ScriptingAPI
            {
            public:
                static sol::state luaState;
                static void Register();
                static void Reset();
            };
        }
    }
}