#include "mainwindow.h"
#include "Board.h"
#include <QApplication>
#include <QRect>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    QScreen* scr = QGuiApplication::primaryScreen();
    QRect rect = scr->geometry();
    MainWindow w(rect);
    w.showMaximized();
    w.startTheGame();
    return a.exec();
}
