use winit::{
    event::{Event, WindowEvent},
    event_loop::{ControlFlow, EventLoop},
    window::{WindowBuilder, Window},
};

use std::{
    thread,
    sync::mpsc::{self, Receiver}
};

// We should have it on top, becouse event_loop for some platform 
// can only be created on the main threads, for example in iOS.
fn main() {
    let event_loop = EventLoop::new();
    let window = WindowBuilder::new().build(&event_loop).unwrap();
    
    let (sender, resiver) = mpsc::channel();
    thread::spawn(move || { engine_main(window, resiver); }); 
    
    event_loop.run(move |event, _, control_flow|  {
        // ControlFlow::Wait pauses the event loop if no events are available to process.
        // This is ideal for non-game applications that only update in response to user
        // input, and uses significantly less power/CPU time than ControlFlow::Poll.
        *control_flow = ControlFlow::Wait;

        match event {
            Event::WindowEvent {
                event: WindowEvent::CloseRequested,
                ..
            } => {
                *control_flow = ControlFlow::Exit
            },
            Event::MainEventsCleared => {
                // Application update code.

                // Queue a RedrawRequested event.
                window.request_redraw();
            },
            Event::RedrawRequested(_) => {
                // Redraw the application.
                //
                // It's preferrable to render in this event rather than in MainEventsCleared, since
                // rendering in here allows the program to gracefully handle redraws requested
                // by the OS.
            },
            _ => {
                sender.send(event.to_static().unwrap()).unwrap();
            }
        }
    });
}

mod ecs;
mod game_engine;
mod render_sys;
mod input_sys;
mod gui_sys;

use game_engine::GameEngine;

fn engine_main(window: Window, resiver: Receiver<Event<'static, ()>>) {
    GameEngine::new(window, resiver)
        .configure()
        .init()
        .idle();
}