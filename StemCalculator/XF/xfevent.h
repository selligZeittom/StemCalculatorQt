#ifndef XFEVENT_H
#define XFEVENT_H

class ISM;
class XFTimer;

class XFEvent
{
public:
    XFEvent();
    virtual ~XFEvent();
    void setTarget(ISM* p1);
    ISM* getTarget();
    void setID(int p1);
    int getID();
    void setDelay(int p1);
    int getDelay();
    void setRepeatCount(int p1);
    int getRepeatCount();
    void setDoNotDelete(bool p1);
    bool getDoNotDelete();
    void setXFTimer(XFTimer* p1);
    XFTimer* getXFTimer();
    void cancel();

private:
    int id;
    ISM* target;
    int delay;
    int repeatCount;
    bool doNotDelete;
    XFTimer* xft;

};

#endif // XFEVENT_H
