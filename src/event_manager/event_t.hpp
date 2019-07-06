#ifndef RAZOR_ENGINE_COMMAND_T_HPP
#define RAZOR_ENGINE_COMMAND_T_HPP

#include <ctime>
#include <cstdint>

enum class event_type: int64_t;

//Accepts components and change it after execute call
//Should not have side effects or state
//NOTE: also it called command pattern
class event_i {
public:
    virtual std::time_t get_timestamp() const = 0;
    virtual event_type get_type_id() const = 0;
    virtual void execute() = 0;
    virtual ~event_i() = default;
};

template<typename Inheritor>
class event_t : public event_i {
public:
    event_type get_type_id() const override;
    std::time_t get_timestamp() const override;
};

template<typename Inheritor>
std::time_t event_t<Inheritor>::get_timestamp() const {
    return std::time_t{};
}

template<typename Inheritor>
event_type event_t<Inheritor>::get_type_id() const {
    return Inheritor::TYPE_ID;
}

#endif //RAZOR_ENGINE_COMMAND_T_HPP
