#ifndef RAZOR_ENGINE_ENTITY_T_HPP
#define RAZOR_ENGINE_ENTITY_T_HPP

#include <cstdlib>
#include <experimental/type_traits>

#include "system_t.hpp"

class entity_i {
public:
    virtual int64_t get_id() const = 0;
    virtual int64_t get_type_id() const = 0;
    virtual ~entity_i() = default;
};

//Container for components
template<typename Inheritor>
class entity_t : entity_i {
private:
    static const int64_t TYPE_ID;
public:
    int64_t get_id() const override;
    int64_t get_type_id() const override;
};

#endif //RAZOR_ENGINE_ENTITY_T_HPP
