#ifndef RAZOR_ENGINE_INPUT_SYSTEM_T_HPP
#define RAZOR_ENGINE_INPUT_SYSTEM_T_HPP

#include "../ecs/system_t.hpp"

class input_system_t : system_t {
public:
    void collect_input() {
        //TODO: now it just key board handle for next time we should separate device
    }
};

#endif //RAZOR_ENGINE_INPUT_SYSTEM_T_HPP
