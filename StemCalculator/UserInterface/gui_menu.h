#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <iostream>
#include <QPushButton>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>

//define some dimensions
#define BTN_HEIGHT 80
#define BTN_NUMBER 3

class GUI_Menu : public QWidget
{
    Q_OBJECT
public:
    explicit GUI_Menu(QWidget* parent = 0);
    virtual ~GUI_Menu();
    void initRelations();
    int getScreenHeight() const;
    int getScreenWidth() const;


private:
    //screen size attributes
    int screenWidth;
    int screenHeight;
    int btnWidth;

    //buttons
    QPushButton* dbManagementButton;
    QPushButton* drawingScreenButton;
    QPushButton* computingScreenButton;

public slots:
    void dbManagementButtonClicked();
    void drawingScreenButtonClicked();
    void computingScreenButtonClicked();
};

#endif // GUI_H
