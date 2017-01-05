#include "LoginDlg.h"
#include "CircularPhoto.h"

LoginDlg::LoginDlg(QWidget *parent) : QDialog(parent)
{
    InitData();
    InitUi();
    InitConnect();
    WarningLayout();
}


LoginDlg::~LoginDlg()
{
}

void LoginDlg::InitData()
{
    DlgMoveing = false;
    DlgMovePosition = QPoint();
}

void LoginDlg::InitUi()
{
    this->setFixedSize(300, 272);
    this->setWindowFlags(Qt::FramelessWindowHint);

    DlgToolBt = new ToolBt();
    Passwd = new QLineEdit();
    UserName = new QLineEdit();
    Passwd->setPlaceholderText(tr("Password"));
    UserName->setPlaceholderText(tr("UserName"));
    LoginBut = new QPushButton(tr("Login"));
    HeaderPhoto = new CircularPhoto();

    OtherLabel = new QHBoxLayout();
    RegisterLabel = new QLabel();
    RegisterLabel->setOpenExternalLinks(true);
    RegisterLabel->setText(tr("<a href=\"http://www.csdn.net/\">Open CSDN"));
    FindPswdLabel = new QLabel();
    FindPswdLabel->setOpenExternalLinks(true);
    FindPswdLabel->setText(tr("<a href=\"http://www.baidu.com/\">Open Baidu"));
    OtherLabel->addWidget(RegisterLabel);
    OtherLabel->addStretch();
    OtherLabel->addWidget(FindPswdLabel);

    WarningLabel = new QLabel(tr("<font color=red>Qt!</font>"));
    WarningLabel->hide();

    AutoRmber = new QHBoxLayout();
    AutoLogin = new QCheckBox(tr("AutoLogin"));
    RmbrPasswd = new QCheckBox(tr("Remember"));
    AutoRmber->addWidget(RmbrPasswd);
    AutoRmber->addStretch();
    AutoRmber->addWidget(AutoLogin);

    DlgWidgetLt = new QVBoxLayout();
    DlgWidgetLt->setContentsMargins(37, 0, 37, 0);
    DlgWidgetLt->addWidget(HeaderPhoto, 0, Qt::AlignTop | Qt::AlignCenter);
    DlgWidgetLt->addWidget(UserName);
    DlgWidgetLt->addWidget(Passwd);
    DlgWidgetLt->addLayout(AutoRmber);
    DlgWidgetLt->addWidget(LoginBut);
    DlgWidgetLt->addLayout(OtherLabel);

    DlgMainLt = new QVBoxLayout();
    DlgMainLt->addWidget(DlgToolBt, 0, Qt::AlignRight | Qt::AlignTop);
    DlgMainLt->addLayout(DlgWidgetLt);
    DlgMainLt->setContentsMargins(0, 0, 0, 0);

    this->setLayout(DlgMainLt);
}

void LoginDlg::InitConnect()
{
    connect(DlgToolBt, SIGNAL(Closed()), this, SLOT(close()));
    connect(DlgToolBt, SIGNAL(Minimi()), this, SLOT(showMinimized()));
    /* login button clicked signal */
    connect(LoginBut, SIGNAL(clicked()), this, SLOT(LoginClicked()));
}

void LoginDlg::WarningLayout()
{
    //this->update();
}

void LoginDlg::LoginClicked()
{
    accept();
}

/* mouse clicked */
void LoginDlg::mousePressEvent(QMouseEvent *event)
{
    DlgMoveing = true;
    DlgMovePosition = event->globalPos() - pos();
    return QDialog::mousePressEvent(event);
}

/* mouse move */
void LoginDlg::mouseMoveEvent(QMouseEvent *event)
{
    if (DlgMoveing && (event->buttons() && Qt::LeftButton) \
        && (event->globalPos()-DlgMovePosition).manhattanLength() > \
            QApplication::startDragDistance())
    {
        move(event->globalPos()-DlgMovePosition);
        DlgMovePosition = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}

/* mouse free */
void LoginDlg::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    DlgMoveing = false;
}
