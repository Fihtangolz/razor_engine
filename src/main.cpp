#include <cstdlib>
#include <experimental/type_traits>

class projection_t {

};

class camera_t {

};

class event_manager_t {

};

//Should be POD object
class component_t {
//static_assert(std::is_pod_v<>);
};

class world_t {

};

class game_engine_t {
public:
    void idle() {
        while(true) {

        }
    }
};

int main(int argc, char *argv[]) {
    game_engine_t engine;
    engine.idle();

    return EXIT_SUCCESS;
}
