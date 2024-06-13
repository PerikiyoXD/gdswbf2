
# godot-cpp
set( GODOT_CPP_SYSTEM_HEADERS ON CACHE BOOL "" FORCE )

add_subdirectory(godot-cpp)

set_target_properties(godot-cpp
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden    # visibility needs to be the same as the main library
)
include(FetchContent)

# lua
FetchContent_Declare(
    lua
    GIT_REPOSITORY git@github.com:UniverseEngine/lua.git
    GIT_TAG origin/swbf2
)
FetchContent_MakeAvailable(lua)

# sol2
FetchContent_Declare(
    sol2
    GIT_REPOSITORY https://github.com/ThePhD/sol2
    GIT_TAG v3.3.0
)
FetchContent_MakeAvailable(sol2)
