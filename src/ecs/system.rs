pub trait System {
    fn start(&mut self);
    fn process(&mut self);
}

