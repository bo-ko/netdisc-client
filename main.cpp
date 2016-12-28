#include "main_interface.h"
#include "login_dlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDlg dlg;
    MainInterface w;

    if(dlg.exec()==QDialog::Accepted) //利用Accepted信号判断enterBtn是否被按下
    {
        w.show();
        return a.exec();
    }
    else
        return 0;
}
