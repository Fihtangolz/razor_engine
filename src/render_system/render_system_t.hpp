#ifndef RAZOR_ENGINE_RENDER_SYSTEM_T_HPP
#define RAZOR_ENGINE_RENDER_SYSTEM_T_HPP

#include <GL/glut.h>

#include "../ecs/system_t.hpp"

//TODO
//class projection_t {
//
//};
//
//class camera_t {
//
//};


class render_system_t : public system_t {
private:
//    display_area_t display_area; TODO
public:
    void start() noexcept override {
        int argc {0};
        char *argv[] {};
        glutInit(&argc, argv);
        glutInitWindowSize(400, 300);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("Hello world!");
    }
    //TODO: show_frame
    void process() noexcept override {

        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
        glEnd();
        glFlush();

        glutSwapBuffers();
    }
};

#endif //RAZOR_ENGINE_RENDER_SYSTEM_T_HPP
