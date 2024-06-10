# SPDX-License-Identifier: Unlicense

target_sources(${PROJECT_NAME}
    PRIVATE
        "SWBF2/Chunks/ChunkHeader.cpp"
        "SWBF2/Chunks/ChunkProcessor.cpp"
        "SWBF2/Chunks/ModelChunk.cpp"
        "SWBF2/Chunks/ModelSegmentChunk.cpp"
        "SWBF2/Chunks/StreamReader.cpp"
        "SWBF2/Chunks/UcfbChunk.cpp"
        "SWBF2/Chunks/WorldChunk.cpp"
        "SWBF2/Model.cpp"
        "SWBF2/Models.cpp"
        "Core.cpp"
        "Core.hpp"
        "RegisterExtension.cpp"
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "src"
)
