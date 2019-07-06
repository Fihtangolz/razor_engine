#ifndef RAZOR_ENGINE_EVENT_MANAGER_T_HPP
#define RAZOR_ENGINE_EVENT_MANAGER_T_HPP

#include <vector>
#include <functional>

#include "event_t.hpp"
#include "inbuilt_event.hpp" //TODO

using event_listener_t = std::function<void()>*;

class event_manager_t {
private:
    std::vector<event_i*> event_queue;
    event_listener_t _listener; //TODO
public:
    void process_event() {
        for(auto&& event : event_queue) {
            event->execute();
            if(event->get_type_id() == engine_terminate_t::TYPE_ID) {
                _listener->operator()();
            }
        }
    }
    template<typename EventType, typename... Args>
    void send_event(Args&&... args) {
        event_queue.push_back(new EventType{args...});
    }
    void subscribe(event_type et, event_listener_t listener) {
        _listener = listener;
    }
    void unsubcribe(event_type et, event_listener_t listener) {

    }
};

#endif //RAZOR_ENGINE_EVENT_MANAGER_T_HPP
