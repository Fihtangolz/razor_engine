#include "game_engine_t.hpp"

void game_engine_t::idle() {
    bool is_active {true};
    while(is_active) {
        //TODO: how should we make sure that we are the last listener?
        std::function terminate_listener = [&](){ is_active = false; };
        //TODO: only system can subscribe to event
        event_manager.subscribe(engine_terminate_t::TYPE_ID, &terminate_listener);
        event_manager.process_event();

        render_system.show_frame();
        input_system.collect_input();

        //TESTED CODE
        event_manager.send_event<engine_terminate_t>();
    }
}