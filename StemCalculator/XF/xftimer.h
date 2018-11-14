#ifndef XFTIMER_H
#define XFTIMER_H

#include <QObject>
class QTimer;
class XFEvent;

class XFTimer  : public QObject
{
    Q_OBJECT
public:
    XFTimer();
    virtual ~XFTimer();
    void cancel();
    void setQTimer(QTimer* p1);
    QTimer* getQTimer();
    void setXFEvent(XFEvent* p1);
    XFEvent* getXFEvent();

public slots:
    void onTimeout();
private:
    QTimer* t;
    XFEvent* e;

};

#endif // XFTIMER_H
