#include "main_interface.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainInterface w;
    w.show();

    return a.exec();
}
