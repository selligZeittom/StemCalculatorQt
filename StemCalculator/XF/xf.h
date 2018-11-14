#ifndef XF_H
#define XF_H

#include <QApplication>
#include <QTimer>
#include <QMap>

class XFEvent;
class XFTimer;

class XF : public QApplication
{
    friend class XFTimer;
    Q_OBJECT
public:
    static XF& getInstance();
    void pushEvent(XFEvent* p1);
    int exec();

private:
    void pushElapsedEvent(XFEvent* p1);


signals:
    void dispatch(XFEvent* p1);

private slots:
    void onDispatch(XFEvent* p1);

private /*methods*/:
    XF();
    XF(const XF&);
    void operator=(const XF&);
    int fake;
    virtual ~XF();

    static XF* instance;
    QMap<int,XFTimer*> timerList;
};

#endif // XF_H
