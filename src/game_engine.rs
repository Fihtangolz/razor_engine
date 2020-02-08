use crate::ecs;
use ecs::system::System;

use crate::render_sys::render_sys::RenderSys;
use crate::input_sys::InputSys;
use crate::gui_sys::GuiSys;
use crate::sound_sys::SoundSys;

use winit::{
    window::Window,
    event::Event,
};

use std::{
    sync::mpsc::Receiver,
    vec::Vec,
};

// struct BaseSystem<Sys: System> {
//     sys: Sys,
//     enable: bool,
// }

pub struct GameEngine {
    systems: Vec<Box<dyn System>>, 
}

impl GameEngine {
    pub fn new(window: Window, resiver: Receiver<Event<'static, ()>>) -> Self {
        Self { systems: vec![
            Box::new(RenderSys::new(window)), 
            Box::new(InputSys::new(resiver)),
            Box::new(GuiSys::new()),
            Box::new(SoundSys::new()),
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