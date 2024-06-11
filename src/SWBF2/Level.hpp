
#pragma once

#include <godot_cpp/classes/node3d.hpp>

namespace SWBF2
{
    class Level : public godot::Node3D {
        GDCLASS(Level, godot::Node3D)

    public:
        Level() {}
        ~Level() = default;

        virtual void _ready() override;

        void LoadMeshes();

        void _process(double delta_time) override;

        void activate(bool active = true);
        bool active() const;

    protected:
        static void _bind_methods();
    };
}
