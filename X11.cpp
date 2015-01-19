#include "X11.h"

#include <iostream>

X11::~X11()
{
    XCloseDisplay( display );
}

XEvent X11::getEvent()
{
    return event;
}

int X11::drawPoint(int x, int y)
{
    return XDrawPoint(display, window, defaultGC, x, y);
}

int X11::drawLine(int x1, int y1, int x2, int y2)
{
    return XDrawLine(display, window, defaultGC, x1, y1, x2, y2);
}

int X11::drawRect(int x, int y, int width, int height)
{
    return XFillRectangle( display, window, defaultGC, x, y, width, height );
}

bool X11::setFColor(const char *colorName)
{
    XColor color1, exact_color;
    Status rc = XAllocNamedColor(display, colormap, colorName, &color1, &exact_color);
    XSetForeground(display, defaultGC, color1.pixel);
    if( rc == 0 )
        return false;
    return true;
}

bool X11::setFColor(unsigned char red, unsigned char green, unsigned char blue){
    XColor color;
    color.red   = red  *256;
    color.green = green*256;
    color.blue  = blue *256;
    Status rc = XAllocColor(display, colormap, &color);
    XSetForeground(display, defaultGC, color.pixel);
    if( rc == 0 )
        return false;
    return true;
}

bool X11::openDisplay()
{
    // Соединиться с X сервером
    if( ( display = XOpenDisplay( getenv("DISPLAY" ) ) ) == NULL ) {  // Соединиться с X сервером,
       return false;
    }
    screen = DefaultScreen( display );
    defaultGC = DefaultGC(display, screen);
    return true;
}

bool X11::createWindow(int x, int y, int width, int height)
{

    window = XCreateSimpleWindow( display, RootWindow( display, screen ),     // Создать окно
                             x, y, width, height, 1,
                             BlackPixel( display, screen ), WhitePixel( display, screen ) );

    XStoreName(display, window, "XLib applicaton");
    colormap = DefaultColormap(display, screen);

  /* // Do not work x,y propertyes
    int dw = XDisplayWidth(display, 0);
    int dh = XDisplayHeight(display, 0);
    int _x = dw/2 - width/2;
    int _y = dh/2 - height/2;

    window = XCreateSimpleWindow( display, RootWindow( display, screen ),     // Создать окно
                             x, y, width, height, 1,
                             BlackPixel( display, screen ), WhitePixel( display, screen ) );
    */

    XSelectInput( display, window, ExposureMask | KeyPressMask );  // На какие события будем реагировать?
    XMapWindow( display, window );// Вывести окно на экран
    return true;
}

int X11::closeDisplay()
{
    // Закрыть соединение с X сервером
    return XCloseDisplay( display );
}

int X11::nextEvent()
{
    return XNextEvent( display, &event );
}
