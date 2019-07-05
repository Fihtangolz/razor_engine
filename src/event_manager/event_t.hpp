#ifndef RAZOR_ENGINE_COMMAND_T_HPP
#define RAZOR_ENGINE_COMMAND_T_HPP

#include <ctime>

enum class event_type: int64_t;

//Accepts components and change it after execute call
//NOTE: also it called command pattern
class event_i {
public:
    virtual std::time_t get_timestamp() = 0; //TODO
    virtual event_type get_type_id() = 0;
    virtual void execute() = 0;
    virtual ~event_i() = default;
};

template<typename Inheritor>
class event_t : event_i {
public:
    event_type get_type_id() override;
};


#endif //RAZOR_ENGINE_COMMAND_T_HPP
