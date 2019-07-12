#include <cstdlib>
#include "game_engine_t.hpp"

int main(int argc, char *argv[]) {
    game_engine_t engine;
    engine.configure(argc, argv);
    engine.initialize();
    engine.idle();

    return EXIT_SUCCESS;
}

