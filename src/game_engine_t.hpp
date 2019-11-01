#ifndef RAZOR_ENGINE_GAME_ENGINE_T_HPP
#define RAZOR_ENGINE_GAME_ENGINE_T_HPP

#include <experimental/type_traits>
#include <vector>
#include <memory>

#include "ecs/system_t.hpp"
#include "render_system/render_system_t.hpp"
#include "input_system/input_system_t.hpp"
#include "movement_system_t/movement_system_t.hpp"
#include "event_manager/event_manager_t.hpp"
#include "event_manager/inbuilt_event.hpp"
#include "sound_system_t.hpp"

class world_t {

};

class game_engine_t {
private:
    world_t world;
    std::vector<system_t*> systems {
        new sound_system_t{},
        new render_system_t{},
//        std::make_unique<movement_system_t>(),
        //    gui_system_t  gui_system;
//        std::make_unique<input_system_t>(),
    };

    event_manager_t event_manager;
public:
    void configure(int argc, char* argv[]) noexcept;
    void initialize() noexcept;
    void idle() noexcept;
};

#endif //RAZOR_ENGINE_GAME_ENGINE_T_HPP
