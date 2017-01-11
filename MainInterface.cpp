#include "MainInterface.h"

MainInterface::MainInterface(QWidget *parent)
    : QWidget(parent)
{
    InitData();
    InitUi();
    InitConnect();
}

MainInterface::~MainInterface()
{}

void MainInterface::InitData()
{
    MainMoveing = false;
    MainMovePosition = QPoint();
}

void MainInterface::InitUi()
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Widget);
    this->setFixedSize(900, 650);

    MainToolBt = new ToolBt();
    MainLt = new QVBoxLayout();
    MainLt->addWidget(MainToolBt, 0, Qt::AlignTop | Qt::AlignRight);
    MainLt->setContentsMargins(0, 0, 0, 4);

    this->setLayout(MainLt);
}

void MainInterface::InitConnect()
{
    connect(MainToolBt, SIGNAL(Closed()), this, SLOT(close()));
    connect(MainToolBt, SIGNAL(Minimi()), this, SLOT(showMinimized()));
}

/* mouse clicked */
void MainInterface::mousePressEvent(QMouseEvent *event)
{
    MainMoveing = true;
    MainMovePosition = event->globalPos() - pos();
    return QWidget::mousePressEvent(event);
}

/* mouse move */
void MainInterface::mouseMoveEvent(QMouseEvent *event)
{
    if (MainMoveing && (event->buttons() && Qt::LeftButton) \
        && (event->globalPos()-MainMovePosition).manhattanLength() > \
            QApplication::startDragDistance())
    {
        move(event->globalPos()-MainMovePosition);
        MainMovePosition = event->globalPos() - pos();
    }
    return QWidget::mouseMoveEvent(event);
}

/* mouse free */
void MainInterface::mouseReleaseEvent(QMouseEvent *event)
{
    MainMoveing = false;
    QWidget::mouseReleaseEvent(event);
}
