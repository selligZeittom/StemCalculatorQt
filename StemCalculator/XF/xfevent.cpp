#include "xfevent.h"
#include "xftimer.h"

XFEvent::XFEvent()
{
    target = nullptr;
    id = 0;
    delay = 0;
    xft = nullptr;
    repeatCount=0;
    doNotDelete=false;
}

XFEvent::~XFEvent()
{
    if (xft)
    {
        delete xft;
    }
}

void XFEvent::setTarget(ISM *p1)
{
    target = p1;
}

ISM *XFEvent::getTarget()
{
    return target;
}

void XFEvent::setID(int p1)
{
    id = p1;
}

int XFEvent::getID()
{
    return id;
}

void XFEvent::setDelay(int p1)
{
    delay = p1;
}

int XFEvent::getDelay()
{
    return delay;
}

void XFEvent::setRepeatCount(int p1)
{
    repeatCount = p1;
}

int XFEvent::getRepeatCount()
{
    return repeatCount;
}

void XFEvent::setDoNotDelete(bool p1)
{
    doNotDelete = p1;
}

bool XFEvent::getDoNotDelete()
{
    return doNotDelete;
}

void XFEvent::setXFTimer(XFTimer *p1)
{
    xft = p1;
}

XFTimer *XFEvent::getXFTimer()
{
    return xft;
}

void XFEvent::cancel()
{
    if (xft)
    {
        xft->cancel();
        delete xft;
        xft=nullptr;
    }
}
