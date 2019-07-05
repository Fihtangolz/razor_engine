#include "entity_t.hpp"

int64_t entity_t::get_id() const {
    return reinterpret_cast<int64_t>(this);
}

int64_t entity_t::get_type_id() const {
    return Inheritor::TYPE_ID;
}