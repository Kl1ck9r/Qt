#include "game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game w;
    w.setWindowTitle("Redaction");
    w.show();
    return a.exec();
}
