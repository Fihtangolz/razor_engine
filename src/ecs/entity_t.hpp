#ifndef RAZOR_ENGINE_ENTITY_T_HPP
#define RAZOR_ENGINE_ENTITY_T_HPP

#include <cstdlib>
#include <initializer_list>
#include <vector>
#include <experimental/type_traits>

#include "system_t.hpp"
#include "component_t.hpp"

using entity_id_t = int64_t;
using entity_type_id_t = int64_t;

class entity_i {
public:
    virtual entity_id_t get_id() const = 0;
    virtual entity_type_id_t get_type_id() const = 0;
    virtual ~entity_i() = default;
};

//Container for components
template<typename Inheritor>
class entity_t : entity_i {
    std::vector<component_t> components;
public:
    entity_t(std::initializer_list<component_t> l) : components{l} {}
    entity_id_t get_id() const override;
    entity_type_id_t get_type_id() const override;
};

template<typename Inheritor>
entity_id_t entity_t<Inheritor>::get_id() const {
    return reinterpret_cast<int64_t>(this);
}

template<typename Inheritor>
entity_type_id_t entity_t<Inheritor>::get_type_id() const {
    return Inheritor::TYPE_ID;
}

#endif //RAZOR_ENGINE_ENTITY_T_HPP
