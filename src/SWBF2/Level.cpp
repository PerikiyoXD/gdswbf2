
#include "Native/Chunks/ChunkProcessor.hpp"

#include "Level.hpp"

namespace SWBF2
{
    void Level::_ready()
    {
        SWBF2::Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/cor/cor1.lvl");
    }

    void Level::_process(double delta_time)
    {
    }

    void Level::activate(bool active)
    {
    }

    bool Level::active() const
    {
        return true;
    }

    void Level::_bind_methods()
    {
    }
}
