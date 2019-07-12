#ifndef RAZOR_ENGINE_KEYBOARD_T_HPP
#define RAZOR_ENGINE_KEYBOARD_T_HPP

#include <X11/Xlib.h>

class keyboard_t : input_device_t final {
public:
    void tick() final {
        int x=-1,y=-1;
        XEvent event;
        int button;
        Display *display = XOpenDisplay(NULL);
        if (display == NULL) {
            fprintf(stderr, "Cannot connect to X server!\n");
            exit (EXIT_FAILURE);
        }
        Window root= XDefaultRootWindow(display);
        XGrabPointer(display, root, False, ButtonPressMask, GrabModeAsync,
                     GrabModeAsync, None, None, CurrentTime);

        XSelectInput(display, root, ButtonPressMask) ;
        while(1){
            XNextEvent(display,&event);
            switch(event.type){
                case ButtonPress:
                    switch(event.xbutton.button){
                        case Button1:
                            x=event.xbutton.x;
                            y=event.xbutton.y;
                            button=Button1;
                            break;

                        case Button3:
                            x=event.xbutton.x;
                            y=event.xbutton.y;
                            button=Button3;
                            break;
                        default:
                            break;

                    }
                    break;
                default:
                    break;
            }
            if(x>=0 && y>=0)break;
        }
        if(button==Button1)printf("leftclick at %d %d \n",x,y);
        else printf("rightclick at %d %d \n",x,y);
        printf("some at %d %d \n",x,y);
        XCloseDisplay(display);
    }
};

#endif //RAZOR_ENGINE_KEYBOARD_T_HPP
