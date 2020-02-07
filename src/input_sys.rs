use crate::ecs::system::System;
use std::sync::mpsc::Receiver;
use winit::event::{Event, DeviceEvent, ElementState};

pub struct InputSys {
    resiver: Receiver<Event<'static, ()>>,
}

impl InputSys {
    pub fn new(resiver: Receiver<Event<'static, ()>>) -> Self {
        Self{resiver}
    }
}

impl System for InputSys {
    fn start(&mut self) {
        
    }

    fn process(&mut self) {
        //FIXME: now a simple stub for logging mouse click, also may be are we need event's buffering?
        let event = self.resiver.recv().unwrap();
        match event {
            Event::DeviceEvent{ event, .. } => match event {
                DeviceEvent::Button { button, state } => match state {
                    ElementState::Pressed => println!("mouse button {} pressed", button),
                    ElementState::Released => println!("mouse button {} released", button),
                },
                _ => (),
            },
            _ => (),
        }
    }
}