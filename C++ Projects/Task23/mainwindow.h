#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Board.h"
#include "ToolWidget.h"
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QRect, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Board* board_;
    ToolWidget* toolWidget_;
    QLabel* scoreCounter_;

public:

    void startTheGame();
    void keyPressEvent(QKeyEvent*) override;

    void Close();

    void print();
};

#endif // MAINWINDOW_H
