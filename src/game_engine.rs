use crate::ecs;
use ecs::system::System;
use crate::render_sys::RenderSys;
use crate::input_sys::InputSys;

use winit::{
    window,
    event::Event,
};

use std::sync::mpsc::Receiver;

pub struct GameEngine {
    systems: [Box<dyn System>; 2], //TODO: it is compile time know array, box not needed this
}

impl GameEngine {
    pub fn new(resiver: Receiver<Event<'static, ()>>) -> Self {
        Self { systems: [
            Box::new(RenderSys{}), 
            Box::new(InputSys::new(resiver))
        ] }
    }
    
    pub fn configure(self) -> Self {
        self
    }

    pub fn init(mut self) -> Self {
        self
    }

    pub fn idle(mut self) {
        loop {
            for system in &mut self.systems {
                system.process();
            }
        }
    }
}