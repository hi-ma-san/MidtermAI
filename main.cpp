#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w, w2;

    // Get screen geometry
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // Calculate window size based on screen size
    // Each window takes 35% of screen width and 70% of screen height
    int windowWidth = screenGeometry.width() * 0.35;
    int windowHeight = screenGeometry.height() * 0.70;

    // Calculate spacing between windows
    int spacing = 20;

    // Calculate total width needed for both windows plus spacing
    int totalWidth = windowWidth * 2 + spacing;

    // Calculate starting X position to center both windows
    int startX = (screenGeometry.width() - totalWidth) / 2;

    // Calculate Y position to center windows vertically
    int startY = (screenGeometry.height() - windowHeight) / 2;

    // Set size and position for both windows
    w.resize(windowWidth, windowHeight);
    w2.resize(windowWidth, windowHeight);

    w.move(startX, startY);
    w2.move(startX + windowWidth + spacing, startY);

    w.show();
    w2.show();

    return a.exec();
}
