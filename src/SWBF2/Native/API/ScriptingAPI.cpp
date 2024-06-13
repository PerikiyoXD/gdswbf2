#include "ScriptingAPI.hpp"

#include <godot_cpp/variant/utility_functions.hpp>

#include <iostream>
#include <cassert>

sol::state SWBF2::Native::API::ScriptingAPI::luaState;

void SWBF2::Native::API::ScriptingAPI::Register()
{
    std::cout << "=== opening a state ===" << std::endl;
    luaState = sol::state();
    luaState.open_libraries(sol::lib::base, sol::lib::package);
    // Route lua print to godot print
    luaState.set_function("print", [](const std::string &str) {
        godot::UtilityFunctions::print(str.c_str());
    });
    luaState.script("print('hello from lua!')");
    std::cout << std::endl;

    godot::UtilityFunctions::print("hello world!");
}

void SWBF2::Native::API::ScriptingAPI::Reset()
{
    if (luaState.lua_state() != nullptr)
    {
        luaState.collect_garbage();
    }
    luaState = sol::state();
}