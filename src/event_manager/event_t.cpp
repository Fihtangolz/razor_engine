#include "event_t.cpp"

event_type event_t::get_type_id() override {
    return Inheritor::TYPE_ID;
}