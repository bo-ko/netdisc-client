#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QSize>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QMouseEvent>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>

#include "ToolBt.h"

class MainInterface : public QWidget
{
    Q_OBJECT

public:
    MainInterface(QWidget *parent = 0);
    ~MainInterface();

private:
    bool   MainMoveing;
    QPoint MainMovePosition;

    ToolBt      *MainToolBt;
    QVBoxLayout *MainLt;

    void InitData();
    void InitUi();
    void InitConnect();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // MAININTERFACE_H
