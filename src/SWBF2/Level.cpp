
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/variant/color.hpp>

#include "Native/Chunks/ChunkProcessor.hpp"
#include "Native/Level.hpp"

#include "Level.hpp"

namespace SWBF2
{
    void Level::_ready()
    {
        SWBF2::Native::UcfbChunk::ReadUcfbFile("data/_lvl_pc/cor/cor1.lvl");

        for (auto const &[id, model] : Native::Level::m_models)
        {
            for (auto const &segment : model.m_segments)
            {
                godot::MeshInstance3D *meshInstance = memnew(godot::MeshInstance3D);
                // meshInstance->set_name("_lvl_terrain");

                add_child(meshInstance);

                godot::PackedVector3Array vertices;
                godot::PackedVector3Array normals;
                //godot::PackedVector3Array tangents;
                godot::PackedColorArray colors;
                godot::PackedVector2Array uvs;
                godot::PackedInt32Array indices;

                for (const auto &position : segment.m_verticesBuf.m_positions)
                {
                    vertices.push_back({ position.x, position.y, position.z });
                }

                for (const auto &normal : segment.m_verticesBuf.m_normals)
                {
                    normals.push_back({ normal.x, normal.y, normal.z });
                }

                /*for (uint32_t i = 0; i < segment.m_verticesBuf.m_tangents.size(); i++)
                {
                    tangents.push_back({ segment.m_verticesBuf.m_tangents[i].x, segment.m_verticesBuf.m_tangents[i].y, segment.m_verticesBuf.m_tangents[i].z });
                }*/

                for (const auto &color : segment.m_verticesBuf.m_colors)
                {
                    colors.push_back({(float) color.r / 255.0f,
                                      (float) color.g / 255.0f,
                                      (float) color.b / 255.0f,
                                      (float) color.a / 255.0f});
                }

                for (const auto &texCoord : segment.m_verticesBuf.m_texCoords)
                {
                    uvs.push_back({ texCoord.x, texCoord.y });
                }

                for (uint32_t i = 0; i < segment.m_indicesBuf.m_indices.size(); i++)
                {
                    indices.push_back({ segment.m_indicesBuf.m_indices[i] });
                }

                godot::Array arrays;
                arrays.resize(godot::ArrayMesh::ARRAY_MAX);
                arrays[godot::ArrayMesh::ARRAY_VERTEX] = vertices;
                arrays[godot::ArrayMesh::ARRAY_NORMAL] = normals;
                //arrays[godot::ArrayMesh::ARRAY_TANGENT] = tangents;
                arrays[godot::ArrayMesh::ARRAY_COLOR] = colors;
                arrays[godot::ArrayMesh::ARRAY_TEX_UV] = uvs;
                arrays[godot::ArrayMesh::ARRAY_INDEX] = indices;

                godot::ArrayMesh *arrMesh = memnew(godot::ArrayMesh);
                arrMesh->add_surface_from_arrays(godot::Mesh::PRIMITIVE_TRIANGLE_STRIP, arrays);

                meshInstance->set_mesh(arrMesh);
            }
        }
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
