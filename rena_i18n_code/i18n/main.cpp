#include "mainwindow.h"

#include <QApplication>
#include "xlsx_to_i18n.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
   rena_i18n_cfile_create();
   rena_i18n_hfile_create();
//    a.quit();
//    a.exit();
    return a.exec();
}
