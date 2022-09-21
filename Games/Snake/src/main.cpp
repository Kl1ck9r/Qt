#include "mainwindow.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow snake;
    snake.show();




    return a.exec();
}