#ifndef RAZOR_ENGINE_GAME_ENGINE_T_HPP
#define RAZOR_ENGINE_GAME_ENGINE_T_HPP

#include <experimental/type_traits>

#include "render_system/render_system_t.hpp"
#include "input_system/input_system_t.hpp"
#include "event_manager/event_manager_t.hpp"
#include "event_manager/inbuilt_event.hpp"

class world_t {

};

class game_engine_t {
private:
    world_t world;

//    sound_system_t sound_system; TODO
    render_system_t render_system;
    input_system_t input_system;

    event_manager_t event_manager;
public:
    void idle() {
        bool is_active {true};
        while(is_active) {
            //TODO: how should we make sure that we are the last listener?
            std::function terminate_listener = [&](){ is_active = false; };
            //TODO: only system can subscribe to event
            event_manager.subscribe(engine_terminate_t::TYPE_ID, &terminate_listener);
            render_system.show_frame();
            input_system.collect_input();
        }
    }
};

#endif //RAZOR_ENGINE_GAME_ENGINE_T_HPP
