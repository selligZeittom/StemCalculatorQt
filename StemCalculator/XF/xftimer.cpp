#include "xftimer.h"
#include "xf.h"

XFTimer::XFTimer()
{
    t = nullptr;
    e = nullptr;
}

XFTimer::~XFTimer()
{
    if (t)
    {
        delete t;
    }
}

void XFTimer::cancel()
{
    t->stop();
    delete t;
    t = nullptr;
}

void XFTimer::setQTimer(QTimer *p1)
{
    t = p1;
}

QTimer *XFTimer::getQTimer()
{
    return t;
}

void XFTimer::setXFEvent(XFEvent *p1)
{
    e = p1;
}

XFEvent *XFTimer::getXFEvent()
{
    return e;
}

void XFTimer::onTimeout()
{
    XF::getInstance().pushElapsedEvent(e);
}
