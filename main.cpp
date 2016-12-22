#include "main_interface.h"
#include "login_dlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDlg dlg;
    if(dlg.exec() != QDialog::Accepted)
        return 0;
    MainInterface w;
    w.show();

    return a.exec();
}
