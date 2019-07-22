#ifndef RAZOR_ENGINE_DAMAGE_SYSTEM_T_HPP
#define RAZOR_ENGINE_DAMAGE_SYSTEM_T_HPP

enum class damage_type_t {
    //Ignore any resist and just subtract from health.
    PURE,
    MAGICAL,
    PHYSICAL
};

struct health_t : component_t {
    uint64_t max_health;
    uint64_t current_health;
};

struct damage_t : component_t {
    entity_id_t source;
    damage_type_t damage_type;
    uint64_t value;
};

enum class apply_status_t {
    //Not yet applied. In the current process, it will be applied
    PENDING,
    //Already applied.
    APPLIED,
    //Already applied. In current process, it will be removed.
    REMOVING,
};

struct modifer_t : component_t {
    int type;
    apply_status_t apply_status;
    int64_t value;
};

struct resistance_t : component_t {
    int magical;
    int physical;
};

struct invulnerability_t : component_t {};

struct unattackable_t : component_t {};

struct magic_immunity_t : component_t {};

enum class attack_type_t {
    MELEE,
    RANGE,
};

struct attacker_t : component_t {
    attack_type_t attack_type;
    uint64_t attack_range;
    uint64_t min_applied_attack;
    uint64_t max_applied_attack;
};

class damage_system_t : system_t {
public:
    void process() noexcept override {

    }
};

#endif //RAZOR_ENGINE_DAMAGE_SYSTEM_T_HPP
