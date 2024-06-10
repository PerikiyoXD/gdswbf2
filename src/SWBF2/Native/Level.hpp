
#pragma once

#include "Models/Model.hpp"

#include "World.hpp"

namespace SWBF2::Native
{
    class Level {
    public:
        static World m_world;

        static std::unordered_map<std::string, Model> m_models;
    };
}
