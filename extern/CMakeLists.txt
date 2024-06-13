
# godot-cpp
set( GODOT_CPP_SYSTEM_HEADERS ON CACHE BOOL "" FORCE )

add_subdirectory(godot-cpp)

set_target_properties(godot-cpp
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden    # visibility needs to be the same as the main library
)

# DirectXTex
set(BUILD_TOOLS OFF CACHE BOOL "" FORCE)
set(BUILD_SAMPLE OFF CACHE BOOL "" FORCE)
set(BUILD_DX11 OFF CACHE BOOL "" FORCE)
set(BUILD_DX12 OFF CACHE BOOL "" FORCE)

add_subdirectory(DirectXTex EXCLUDE_FROM_ALL)
