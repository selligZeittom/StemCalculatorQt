#ifndef GUI_COMPUTING_H
#define GUI_COMPUTING_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class ScreenManager;

class GUI_Computing : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_Computing(QWidget* parent = 0);
    virtual ~GUI_Computing();
    void initRelations(ScreenManager* screenManager);

private:
    //the screen manager
    ScreenManager* theScreenManager;

    //style sheet for objects
    QString btnStylesheet;

    //graphical objects
    QPushButton* menuButton;

public slots:
    void menuButtonClicked();
};

#endif // GUI_COMPUTING_H
