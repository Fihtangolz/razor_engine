#ifndef RAZOR_ENGINE_MOVEMENT_SYSTEM_T_HPP
#define RAZOR_ENGINE_MOVEMENT_SYSTEM_T_HPP

#include "../ecs/component_t.hpp"
#include "../ecs/system_t.hpp"

struct rotate_component_t : component_t {
    int w;
    int x;
    int y;
    int z;
};

struct move_component_t : component_t {
};

class movement_system_t : public system_t {
public:
    void start() noexcept override {}
    //TODO: move
    void process() noexcept override {

    }
};

#endif //RAZOR_ENGINE_MOVEMENT_SYSTEM_T_HPP
