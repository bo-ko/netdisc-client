#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QSize>
#include <QImage>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class MainInterface : public QWidget
{
    Q_OBJECT

public:
    MainInterface(QWidget *parent = 0);
    ~MainInterface();
};

#endif // MAININTERFACE_H
