use crate::ecs;
use ecs::system::System;
use crate::render_sys::RenderSys;

pub struct GameEngine<S: System> {
    systems: [S]
}

impl<S> GameEngine<S> {
    pub fn new() -> Self {
        Self { systems: [ RenderSys{} ] }
    }
    
    pub fn configure(self) -> Self {
        self
    }

    pub fn init(self) -> Self {
        self
    }

    pub fn idle(self) {
        loop {
            self.systems.map(|s| s.process());
        }
    }
}