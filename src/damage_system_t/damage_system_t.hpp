#ifndef RAZOR_ENGINE_DAMAGE_SYSTEM_T_HPP
#define RAZOR_ENGINE_DAMAGE_SYSTEM_T_HPP

class damage_component_t : component_t {
    int source; //TODO entity id
    int value;
};

class damage_system_t : system_t {
public:
    void move() {

    }
};

#endif //RAZOR_ENGINE_DAMAGE_SYSTEM_T_HPP
