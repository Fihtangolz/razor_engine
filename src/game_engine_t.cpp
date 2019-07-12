#include "game_engine_t.hpp"
#include "input_system/keyboard_t.hpp"
#include "input_system/mouse_t.hpp"

void game_engine_t::configure(int argc, char *argv[]) noexcept {

}

void game_engine_t::initialize() noexcept {
    input_system.add_device(keyboard_t{});
    input_system.add_device(mouse_t{});
}

void game_engine_t::idle() noexcept {
    //TODO: fsm
    bool is_active {true};
    while(is_active) {
        //TODO: how should we make sure that we are the last listener?
        std::function terminate_listener = [&](){ is_active = false; };
        //TODO: only system can subscribe to event
        event_manager.subscribe(engine_terminate_t::TYPE_ID, &terminate_listener);
        event_manager.process_event();

        for(auto&& system : systems) {
            system.process();
        }

        //TESTED CODE
        event_manager.send_event<engine_terminate_t>();
    }
}