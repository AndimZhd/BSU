#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QGridLayout>
#include "MyLabel.h"


class Board: public QWidget{
private:
    QRect rect_;
    friend class MainWindow;
    bool isChanged_ = true;
    int score_ = 0;
    int board_[4][4] = {0};
    bool hasWon_ = false;
    MyLabel* labelDataBase[4][4];

public:
    Board(QRect);

public:
    void fillLabelMatrix();

public:
    bool getStatus(){return hasWon_;}

    void setStatus(bool status){
        hasWon_ = status;
    }

    void print();

    int getFreeCellNumber();

    void locateNewNumber(int, int);
    void generateANumber();

    bool checkAllNeighbors();

    bool isOver();
    bool hasWon();

    void moveLeft();

    void moveUp();

    void moveRight();

    void moveDown();
};

#endif // BOARD_H
