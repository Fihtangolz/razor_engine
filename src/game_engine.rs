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
    iter::Filter,
};

struct BaseSystem {
    sys: Box<dyn System>,
    enable: bool,
}

impl System for BaseSystem {
    fn start(&mut self) {
        self.sys.start();
    }

    fn process(&mut self) {
        self.sys.process();
    }
}

pub struct GameEngine {
    systems: Vec<BaseSystem>, 
}

impl GameEngine {
    pub fn new(window: Window, resiver: Receiver<Event<'static, ()>>) -> Self {
        Self { 
            systems: vec![
                BaseSystem{ sys: Box::new(RenderSys::new(window)), enable: true},
                BaseSystem{ sys: Box::new(InputSys::new(resiver)), enable: true},
                BaseSystem{ sys: Box::new(GuiSys::new()), enable: true},
                BaseSystem{ sys: Box::new(SoundSys::new()), enable: true},
            ] 
        }
    }
    
    pub fn configure(self) -> Self {
        self
    }

    pub fn init(mut self) -> Self {
        self.systems.iter_mut().
            map(|s| s.start());
        self
    }

    pub fn idle(mut self) {
        loop {
            self.systems.iter_mut()
                .filter(|s| s.enable)
                .map(|s| s.process());
        }
    }
}