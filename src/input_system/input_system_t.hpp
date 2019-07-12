#ifndef RAZOR_ENGINE_INPUT_SYSTEM_T_HPP
#define RAZOR_ENGINE_INPUT_SYSTEM_T_HPP

#include <iostream>
#include <vector>

#include "../ecs/system_t.hpp"
#include "../event_manager/event_manager_t.hpp"

class input_device_t {
public:
    virtual void tick() = 0;
};

class input_system_t : system_t {
private:
    event_manager_t* event_manager {nullptr};
    std::vector<input_device_t*>  devices;
public:
    void add_device(input_device_t* device) {
        devices.push_back(device);
    }

    void remove_device(input_device_t* device) {
        auto pos = std::find(devices.begin(), devices.end(), device);
        if(pos != devices.end()) {
            devices.erase(pos);
        }
    }

    //TODO: collect_input
    void process() noexcept override {
        for(auto&& device : devices) {
            device->tick();
        }
    }
};

#endif //RAZOR_ENGINE_INPUT_SYSTEM_T_HPP
