mod ecs;
mod game_engine;
mod render_sys;

use game_engine::GameEngine;

fn main() {
    GameEngine::new()
        .configure()
        .init()
        .idle();
}