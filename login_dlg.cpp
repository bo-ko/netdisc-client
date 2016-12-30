#include "login_dlg.h"
#include "circularphoto.h"

LoginDlg::LoginDlg(QWidget *parent) : QDialog(parent)
{
    _width = this->width(); // widget width
    InitLgnDlgUI();
    WarningLayout();
}


LoginDlg::~LoginDlg()
{
}

void LoginDlg::InitLgnDlgUI()
{
    this->setFixedSize(280, 256);
    this->setWindowFlags(Qt::FramelessWindowHint);

    /* new widgets */
    Passwd = new QLineEdit(this);
    UserName = new QLineEdit(this);
    LoginBut = new QPushButton(tr("Login"), this);
    HeaderPhoto = new CircularPhoto(this);
    RegisterLabel = new QLabel(this);
    RegisterLabel->setOpenExternalLinks(true);
    RegisterLabel->setText(tr("<a href=\"http://www.csdn.net/\">打开CSDN"));
    FindPswdLabel = new QLabel(this);
    FindPswdLabel->setOpenExternalLinks(true);
    FindPswdLabel->setText(tr("<a href=\"http://www.baidu.com/\">打开Baidu"));

    WarningLabel = new QLabel(tr("<font color=red>Qt!</font>"), this);
    WarningLabel->hide();

    AutoLogin = new QCheckBox(tr("AutoLogin"), this);
    RmbrPasswd = new QCheckBox(tr("Remember"), this);
    /* login button clicked signal */
    connect(LoginBut, SIGNAL(clicked()), this, SLOT(LoginClicked()));

    LoginExitBt = new QToolButton(this);
    LoginHidBt  = new QToolButton(this);
    /* cloce app */
    connect(LoginExitBt, SIGNAL(clicked()), this, SLOT(close()));

    /* Layout */
    LoginExitBt->setGeometry(256, 4, 20, 20);
    LoginHidBt->setGeometry(232, 4, 20, 20);
    HeaderPhoto->setGeometry(108, 28, 64, 64);
    UserName->setGeometry(40, 96, 200, 30);
    Passwd->setGeometry(40, 130, 200, 30);
    AutoLogin->setGeometry(40, 164, 100, 30);
    //int RmbrWidth = RmbrPasswd->width();
    //RmbrPasswd->setGeometry((130+100-RmbrWidth), 164, RmbrWidth, 30);    //
    RmbrPasswd->setGeometry(140, 164, 100, 30);

    LoginBut->setGeometry(40, 198, 200, 30);
    FindPswdLabel->setGeometry(40, 232, 100, 20);
    //int RegisterWidth = RegisterLabel->width();
    //RegisterLabel->setGeometry((130+100-RegisterWidth), 232, RegisterWidth, 20); //
    RegisterLabel->setGeometry(140, 232, 100, 20);
}

void LoginDlg::WarningLayout()
{


    //this->update();
}

void LoginDlg::LoginClicked()
{
    accept();
}
