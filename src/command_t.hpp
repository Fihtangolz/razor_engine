#ifndef RAZOR_COMMAND_T_HPP
#define RAZOR_COMMAND_T_HPP

//Accepts components and change it after execute call
class command_i {
public:
    virtual void execute() = 0;
    virtual ~command_i() = default;
};

#endif //RAZOR_COMMAND_T_HPP
