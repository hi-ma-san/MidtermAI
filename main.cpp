#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w, w2;
    
    // Get the primary screen geometry
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    
    // Calculate window size based on screen size
    // Each window takes ~40% of screen width and ~70% of screen height
    int windowWidth = static_cast<int>(screenGeometry.width() * 0.40);
    int windowHeight = static_cast<int>(screenGeometry.height() * 0.70);
    
    // Spacing between windows
    int spacing = 20;
    
    // Calculate total width needed for both windows and spacing
    int totalWidth = windowWidth * 2 + spacing;
    
    // Calculate starting X position to center both windows horizontally
    int startX = (screenGeometry.width() - totalWidth) / 2 + screenGeometry.x();
    
    // Calculate Y position to center vertically
    int startY = (screenGeometry.height() - windowHeight) / 2 + screenGeometry.y();
    
    // Set size and position for first window
    w.resize(windowWidth, windowHeight);
    w.move(startX, startY);
    
    // Set size and position for second window (to the right of first)
    w2.resize(windowWidth, windowHeight);
    w2.move(startX + windowWidth + spacing, startY);
    
    // Show both windows
    w.show();
    w2.show();
    
    return a.exec();
}
