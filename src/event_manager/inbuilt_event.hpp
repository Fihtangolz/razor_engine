#ifndef RAZOR_ENGINE_INBUILT_EVENT_HPP
#define RAZOR_ENGINE_INBUILT_EVENT_HPP

#include <string>

#include "event_t.hpp"

/* TODO
 * struct event_type {
    enum : int64_t {
        ENGINE_TERMINATE,
        ENGINE_RESUME,
        ENGINE_SUSPEND,
    };

    std::string stringify() {
        switch(et) {
            case event_type::ENGINE_TERMINATE:
                return "ENGINE_TERMINATE";
            case event_type::ENGINE_RESUME:
                return "ENGINE_RESUME";
            case event_type::ENGINE_SUSPEND:
                return "ENGINE_SUSPEND";
        }
    }
}; */

enum class event_type: int64_t {
    ENGINE_TERMINATE,
    ENGINE_RESUME,
    ENGINE_SUSPEND,
};

class engine_terminate_t : public event_t<engine_terminate_t> {
public:
    static const event_type TYPE_ID = {event_type::ENGINE_TERMINATE};
    void execute() override {}
};

#endif //RAZOR_ENGINE_INBUILT_EVENT_HPP
