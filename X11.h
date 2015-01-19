#ifndef X11_H
#define X11_H

#include <X11/Xlib.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>
extern int errno;

class X11{
  private:
    Display *display;
    Window window;
    GC defaultGC;
    XEvent event;
    int screen;
    Colormap colormap;

  public:
    ~X11();
    XEvent getEvent();
    int  drawPoint(int x, int y);
    int  drawLine(int x1, int y1, int x2, int y2);
    int  drawRect(int x, int y, int width, int height);

    bool setFColor(const char* colorName);
    bool setFColor(unsigned char red, unsigned char green, unsigned char blue);

    bool openDisplay();
    bool createWindow(int x, int y, int width, int height);
    int  closeDisplay();
    int  nextEvent();
};

namespace XEventType{
    enum EventType{
        xKeyPress = 2,
        xKeyRelease,
        xButtonPress,
        xButtonRelease,
        xMotionNotify,
        xEnterNotify,
        xLeaveNotify,
        xFocusIn,
        xFocusOut,
        xKeymapNotify,
        xExpose,
        xGraphicsExpose,
        xNoExpose,
        xVisibilityNotify,
        xCreateNotify,
        xDestroyNotify,
        xUnmapNotify,
        xMapNotify,
        xMapRequest,
        xReparentNotify,
        xConfigureNotify,
        xConfigureRequest,
        xGravityNotify,
        xResizeRequest,
        xCirculateNotify,
        xCirculateRequest,
        xPropertyNotify,
        xSelectionClear,
        xSelectionRequest,
        xSelectionNotify,
        xColormapNotify,
        xClientMessage,
        xMappingNotify,
        xGenericEvent,
        xLASTEvent
    };
}

#endif // X11_H
