#ifndef RAZOR_ENGINE_SOUND_SYSTEM_T_HPP
#define RAZOR_ENGINE_SOUND_SYSTEM_T_HPP

#include "ecs/system_t.hpp"

class sound_system_t : public system_t {
public:
    void start() noexcept override {};
    void process() noexcept override {};
};

#endif //RAZOR_ENGINE_SOUND_SYSTEM_T_HPP
