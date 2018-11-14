#include "xf.h"
#include <QApplication>
#include <QDebug>

#include "xfevent.h"
#include "xftimer.h"
#include "ism.h"

XF* XF::instance = nullptr;

XF::XF() : QApplication(fake,(char**) nullptr)
{
    connect(this, SIGNAL(dispatch(XFEvent*)), this, SLOT(onDispatch(XFEvent*)));
}

XF::XF(const XF &) : QApplication(fake,(char**) nullptr)
{
}

void XF::operator=(const XF &)
{
}

XF::~XF()
{

}

XF &XF::getInstance()
{
    if (!instance)
    {
        instance = new XF();
    }
    return *instance;
}

void XF::pushEvent(XFEvent *p1)
{
    if (p1->getDelay() > 0)
    {
        QTimer* t = new QTimer();
        t->setInterval(p1->getDelay());
        t->setSingleShot(true);
        XFTimer* xft = new XFTimer();
        xft->setQTimer(t);
        xft->setXFEvent(p1);
        p1->setXFTimer(xft);
        connect(t,SIGNAL(timeout()),xft,SLOT(onTimeout()));
        t->start();
    }
    else
    {
        emit dispatch(p1);
    }
}

void XF::pushElapsedEvent(XFEvent *p1)
{
    emit dispatch(p1);
}

int XF::exec()
{
    int retval = QApplication::exec();
    delete instance;
    return retval;
}

void XF::onDispatch(XFEvent *p1)
{
    if (p1)
    {
        p1->getTarget()->processEvent(p1);
        int rc = p1->getRepeatCount();
        if (rc > 0)
        {
            p1->setRepeatCount(rc-1);
            pushEvent(p1);
        }
        else if (rc == -1)
        {
            pushEvent(p1);
        }
        else
        {
            p1->cancel();
            if (p1->getDoNotDelete()==false)
            {
                delete p1;
            }
        }
    }
}
