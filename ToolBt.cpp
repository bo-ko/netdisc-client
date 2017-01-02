#include "ToolBt.h"

ToolBt::ToolBt(QWidget *parent) : QWidget(parent)
{
    LoginExitBt = new QToolButton(this);
    LoginMiniBt  = new QToolButton(this);

    LoginExitBt->setGeometry(36, 2, 24, 24);
    LoginMiniBt->setGeometry(64, 2, 24, 24);

    this->setFixedSize(93, 26);
}
