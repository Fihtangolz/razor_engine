#ifndef RAZOR_ENGINE_COMMAND_T_HPP
#define RAZOR_ENGINE_COMMAND_T_HPP

#include <ctime>
#include <cstdint>

enum class event_type: int64_t;

//Accepts components and change it after execute call
//Should not have side effects or state
//NOTE: also it called command pattern
class action_i {
public:
    virtual std::time_t get_timestamp() const = 0;
    virtual event_type get_type_id() const = 0;
    virtual void execute() = 0;
    virtual ~action_i() = default;
};

template<typename Inheritor>
class action_t : public action_i {
private:
    std::vector<action_i*> children;
public:
    event_type get_type_id() const override;
    std::time_t get_timestamp() const override;
};

template<typename Inheritor>
std::time_t action_t<Inheritor>::get_timestamp() const {
    return std::time_t{};
}

template<typename Inheritor>
event_type action_t<Inheritor>::get_type_id() const {
    return Inheritor::TYPE_ID;
}

#endif //RAZOR_ENGINE_COMMAND_T_HPP
