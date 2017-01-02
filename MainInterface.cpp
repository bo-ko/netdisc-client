#include "MainInterface.h"

MainInterface::MainInterface(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowFlags(/*Qt::FramelessWindowHint | */Qt::Widget);
    this->setFixedSize(900, 650);
}

MainInterface::~MainInterface()
{

}
