#ifndef RAZOR_ENGINE_GAME_ENGINE_T_HPP
#define RAZOR_ENGINE_GAME_ENGINE_T_HPP

#include <experimental/type_traits>

#include "render_system/render_system_t.hpp"
#include "input_system/input_system_t.hpp"
#include "movement_system_t/movement_system_t.hpp"
#include "event_manager/event_manager_t.hpp"
#include "event_manager/inbuilt_event.hpp"

class world_t {

};

class game_engine_t {
private:
    world_t world;
    std::array<system_t, 3> systems {
        //    sound_system_t sound_system; TODO
        render_system_t{},
        movement_system_t{},
//    gui_system_t  gui_system;
        input_system_t{},
    };

    event_manager_t event_manager;
public:
    void configure(int argc, char *argv[]) noexcept;
    void initialize() noexcept;
    void idle() noexcept;
};

#endif //RAZOR_ENGINE_GAME_ENGINE_T_HPP
