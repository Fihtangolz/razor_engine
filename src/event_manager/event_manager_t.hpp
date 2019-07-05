#ifndef RAZOR_ENGINE_EVENT_MANAGER_T_HPP
#define RAZOR_ENGINE_EVENT_MANAGER_T_HPP

#include <queue>
#include <functional>

#include "event_t.hpp"

using event_listener_t = std::function<void()>*;

class event_manager_t {
private:
    std::queue<event_i> event_queue;
public:
    void subscribe(event_type et, event_listener_t listener) {

    }
    void unsubcribe(event_type et, event_listener_t listener) {

    }
};

#endif //RAZOR_ENGINE_EVENT_MANAGER_T_HPP
