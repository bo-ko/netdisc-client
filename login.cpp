#include "login.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

Login::Login()
{
    QVBoxLayout *MainLayout;
    MainLayout = new QVBoxLayout(this);
    QHBoxLayout *UserLayout;
    UserLayout = new QHBoxLayout();
    QHBoxLayout *PasswLayout;
    PasswLayout = new QHBoxLayout();
    QHBoxLayout *CtrlButLayout;
    CtrlButLayout = new QHBoxLayout();
    QLabel *UserLabel;
    UserLabel = new QLabel("UserName:");
    QLabel *PasswLabel;
    PasswLabel = new QLabel("Passwd:");
    Passw = new QLineEdit();
    UserName = new QLineEdit();
    LoginBut = new QPushButton("Login");
    CancelBut = new QPushButton("Cancel");
}

void Login::on_cancel_but_clicked()
{
    close();
}
