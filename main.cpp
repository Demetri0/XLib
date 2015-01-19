#include <iostream>
#include "X11.h"

int main( void ){
    X11 X;
    if( ! X.openDisplay() ){
        std::cerr << "Can't connect X server:" << strerror( errno );
        exit(1);
    }
    X.createWindow(10,10,640,480);

    while(true){
        X.nextEvent();
        std::cout << "iter" << std::endl;
        XEvent e = X.getEvent();
        std::cout << e.type << std::endl;
        if( e.type == XEventType::xExpose ){
            X.setFColor(255, 0, 0);
            X.drawRect(20,20, 40, 40);
            X.drawPoint(10,10);
            continue;
        }
        if( e.type == XEventType::xKeyPress ){
            break;
        }
    }

    return 0;
}
