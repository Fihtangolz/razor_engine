use crate::ecs::system::System;

use std::{
    sync::{Arc, mpsc},
    thread
};

use ash::vk;
use winit::window::Window;
use std::mem::MaybeUninit;

// Represent word space.
struct WorldSpace {

}

struct Location {
    x: u64,
    y: u64,
    z: u64,
} 

// Represent a camera in the world. This is just the point in the world from which the projection originates.
struct Camera {
    location: Location,
}

// Represent projection on world
struct Projection {

}

// Represent drowing area on surface
struct Fragment {

}

impl Fragment {
    pub fn new() {

    }
}

struct RenderebleModel {
    model: *mut usize,
    location: Location,
    scale: f32,
}

pub struct RenderSys {
    window: Window,
    surface: vk::SurfaceKHR,
}

impl RenderSys {
    pub fn new(window: Window) -> Self {
        let mut sys: RenderSys = unsafe { MaybeUninit::uninit().assume_init() };
        sys.window = window;
        sys
    }
}

impl System for RenderSys {
    fn start(&mut self) {
        //FIXME: now prepairing surface only for my linux system
        
    }
    
    fn process(&mut self) {
        
        // Create cube representation from vertex
        let vertex_buff: [f64; 24] = [
            -0.25, -0.25, -0.25,
            -0.25,  0.25, -0.25,
             0.25, -0.25, -0.25,
             0.25,  0.25, -0.25,
             0.25, -0.25,  0.25,
             0.25,  0.25,  0.25,
            -0.25, -0.25,  0.25,
            -0.25,  0.25,  0.25,
        ];

        let index_buffer: [u16; 36] = [
            0, 1, 2,
            2, 1, 3,
            2, 3, 4,
            4, 3, 5,
            4, 5, 6,
            6, 5, 7,
            6, 7, 0,
            0, 7, 1,
            6, 0, 2,
            2, 4, 6,
            7, 5, 3,
            7, 3, 1
        ];
    }
}

