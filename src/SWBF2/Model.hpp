
#pragma once

#include <godot_cpp/classes/mesh.hpp>

#include "Types.hpp"

#include "ModelSegment.hpp"

namespace SWBF2
{
    typedef struct _MODEL_INFO
    {
        uint32_t m_unknown[4];
        Vector3<float> m_vertexBox[2];
        Vector3<float> m_visibilityBox[2];
        uint32_t m_faceCount;
    } ModelInfo;

    class Model {
    public:
        Model();
        ~Model() = default;

        std::string m_name;
        std::string m_node;
        ModelInfo m_info;
        std::vector<ModelSegment> m_segments;
    };
}
