use crate::ecs;
use ecs::system::System;
use crate::render_sys::render_sys::RenderSys;
use crate::input_sys::InputSys;

use winit::{
    window::Window,
    event::Event,
};

use std::sync::mpsc::Receiver;

pub struct GameEngine {
    //TODO: it is compile time know array, box not needed this
    systems: [Box<dyn System>; 2], 
}

impl GameEngine {
    pub fn new(window: Window, resiver: Receiver<Event<'static, ()>>) -> Self {
        Self { systems: [
            Box::new(RenderSys::new(window)), 
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