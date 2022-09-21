#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow view(12345);
    view.show();

    return a.exec();
}