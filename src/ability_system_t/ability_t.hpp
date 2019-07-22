#ifndef RAZOR_ENGINE_ABILITY_T_HPP
#define RAZOR_ENGINE_ABILITY_T_HPP

struct ability_t {
    //possible type of target ex tower\boss\creep
    int target_types;
    //cast time
    //toggle
    int cooldown;
    int manacost;
    action_i action;
};

#endif //RAZOR_ENGINE_ABILITY_T_HPP
