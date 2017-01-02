#include "MainInterface.h"
#include "LoginDlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDlg _Dlg;
    MainInterface _MainWidow;

    /* Use the Accepted signal to determine whether the login button was pressed */
    if(_Dlg.exec()==QDialog::Accepted)
    {
        _MainWidow.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
