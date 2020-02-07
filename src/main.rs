use vulkano::{
    instance::{
        self, 
        Instance, 
        InstanceExtensions,
    },
    device::{
        DeviceExtensions,
        Device,
    },
    swapchain::{
        AcquireError, 
        PresentMode, 
        SurfaceTransform, 
        Surface, 
        Swapchain, 
        SwapchainCreationError, 
        ColorSpace, 
    },
    pipeline::{
        GraphicsPipeline, 
        vertex::SingleBufferDefinition
    },
    command_buffer::{
        AutoCommandBufferBuilder, 
        CommandBuffer,
        DynamicState
    },
    framebuffer::Framebuffer,
};

use std::{
    sync::{Arc, mpsc},
    thread
};

use vulkano_win::VkSurfaceBuild;
use winit::{
    WindowBuilder, 
    Window,
    ControlFlow,
    WindowEvent,
    EventsLoop,
};

struct Render {
    // surface: Surface<winit::Window>,
    
}

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

impl Render {
    /// Rendering one frame 
    pub fn run(&mut self) {
        // self.surface
    }
}

fn main() {
    let required_extensions = vulkano_win::required_extensions();
    let instance = Instance::new(None, &required_extensions, None).unwrap();

    /// Window depende code
    //////////////////////////////////////////////////////////////////////////////////////////
    let mut event_loop = EventsLoop::new();
    let surface = WindowBuilder::new().build_vk_surface(&event_loop, instance.clone()).unwrap();

    // let (tx, rx) = mpsc::channel(); TODO use to send and resive message
    thread::spawn(move | | {
        let mut render = Render{};
        loop {
            render.render();
        }
    });

    event_loop.run_forever(|event| {
        match event {
            winit::Event::WindowEvent {
            event: winit::WindowEvent::CloseRequested,
            ..
            } => winit::ControlFlow::Break,
            _ => winit::ControlFlow::Continue,
        }
    });
    ///////////////////////////////////////////////////////////////////////////////////////////

    let physical = instance::PhysicalDevice::enumerate(&instance).next().unwrap();
    let queue_family = physical.queue_families().find(|&q| {
        q.supports_graphics() && surface.is_supported(q).unwrap_or(false)
    }).unwrap();

    let (device, mut queues) = {
        let device_ext = DeviceExtensions { khr_swapchain: true, .. DeviceExtensions::none() };
        Device::new(physical, physical.supported_features(), &device_ext,
            [(queue_family, 0.5)].iter().cloned()).unwrap()
    };
    let queue = queues.next().unwrap();
    let device_ext = DeviceExtensions { khr_swapchain: true, .. DeviceExtensions::none() };
    
    let (device, mut queues) = Device::new(physical, physical.supported_features(), &device_ext,
        [(queue_family, 0.5)].iter().cloned()).unwrap();
    let queue = queues.next().unwrap();

    let (mut swapchain, images) = {
        let caps = surface.capabilities(physical).unwrap();
        let usage = caps.supported_usage_flags;
        let alpha = caps.supported_composite_alpha.iter().next().unwrap();
        let format = caps.supported_formats[0].0;

        let window = surface.window();
        // unlike the triangle example we need to keep track of the width and height so we can calculate
        // render the teapot with the correct aspect ratio.
        let mut dimensions = if let Some(dimensions) = window.get_inner_size() {
            let dimensions: (u32, u32) = dimensions.to_physical(window.get_hidpi_factor()).into();
            [dimensions.0, dimensions.1]
        } else {
            return;
        };

        Swapchain::new(device.clone(), surface.clone(), caps.min_image_count, format, dimensions, 1,
            usage, &queue, SurfaceTransform::Identity, alpha, PresentMode::Fifo, true, None).unwrap()
    };
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // End basic initialization code
    
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
    
    let framebuffer = Framebuffer::start(render_pass.clone())
        .add(image.clone()).unwrap()
        .build().unwrap();
    
    let graphics_pipeline = Arc::new(
        GraphicsPipeline::start()
            .vertex_input(SingleBufferDefinition::<Vertex>::new())
            .vertex_shader(vert_main, ())
            .triangle_list()
            .viewports_dynamic_scissors_irrelevant(1)
            .fragment_shader(frag_main, ())
            .cull_mode_front()
            .front_face_counter_clockwise()
            .depth_stencil_disabled()
            .render_pass(Subpass::from(render_pass.clone(), 0).unwrap())
            .build(device.clone())
            .unwrap(),
    );

    let layout = pipeline.descriptor_set_layout(0).unwrap();
    let set = Arc::new(PersistentDescriptorSet::start(layout.clone())
        .add_buffer(uniform_buffer_subbuffer).unwrap()
        .build().unwrap()
    );

    let command_buffer = AutoCommandBufferBuilder::new(device.clone(), queue.family()).unwrap()
        .draw_indexed(graphics_pipeline.clone(), &DynamicState::none(), vertex_buff, &index_buffer, set.clone(), ()).unwrap()
        .build().unwrap();

    command_buffer.execute(queue);
}
