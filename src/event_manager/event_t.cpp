#include "event_t.hpp"

template<typename Inheritor>
std::time_t event_t<Inheritor>::get_timestamp() {
    return std::time_t{};
}

template<typename Inheritor>
event_type event_t<Inheritor>::get_type_id() {
    return Inheritor::TYPE_ID;
}

