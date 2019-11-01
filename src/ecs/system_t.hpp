#ifndef RAZOR_ENGINE_SYSTEM_T_HPP
#define RAZOR_ENGINE_SYSTEM_T_HPP

//Manage binded component
class system_t {
public:
    virtual void start() noexcept = 0;
    virtual void process() noexcept = 0;
};

#endif //RAZOR_ENGINE_SYSTEM_T_HPP
