#pragma once

#include <godot_cpp/classes/node.hpp>

namespace SWBF2
{
    class Core : public godot::Node {
        GDCLASS(Core, godot::Node)

    public:
        Core();
        ~Core() = default;

        void _ready() override;

    private:
        static void _bind_methods();
    };
}
