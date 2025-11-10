#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w, w2;
    w.show();
    w.show();
    w2.show();
    w.resize(600, 800);
    w2.resize(600, 800);
    w.move(100, 100);
    w2.move(w.x() + w.width() + 10, w.y());
    return a.exec();
}
