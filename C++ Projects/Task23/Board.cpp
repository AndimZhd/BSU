#include "Board.h"
#include<QApplication>
#include <QRect>

Board::Board(QRect rect){
    rect_ = rect;
    this->setFixedSize(rect.height()*0.9, rect.height()*0.9);
    QGridLayout* grid = new QGridLayout();

    grid->setColumnStretch(3, 0);
    this->setLayout(grid);
    fillLabelMatrix();
}

void Board::fillLabelMatrix(){
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++){
            labelDataBase[i][j] = new MyLabel("0", rect_);
            this->layout()->addWidget(labelDataBase[i][j]);
        }
}

int Board::getFreeCellNumber(){
    int result = 0;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(board_[i][j] == 0)
                result++;
        }
    }
    return result;
}

void Board::generateANumber(){
    int twoOrFour = rand()%10;
    twoOrFour = twoOrFour==1 ? 4 : 2;
    int numberOfFreeCells = getFreeCellNumber();
    if(numberOfFreeCells){
        int choosePosition = rand()%numberOfFreeCells;
        locateNewNumber(choosePosition, twoOrFour);
    }

}

void Board::locateNewNumber(int position, int number){
    int counter = 0;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(board_[i][j] == 0) {
                if(counter == position){
                    board_[i][j] = number;
                    return;
                }
                counter++;
            }
        }
    }
}

bool Board::checkAllNeighbors() {
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++) {
            if(i<3)
                if(board_[i+1][j]==board_[i][j])
                    return false;
            if(j<3)
                if(board_[i][j+1]==board_[i][j])
                    return false;
        }
    }
    return true;
}

bool Board::isOver(){
    if(getFreeCellNumber()==0){
        if(checkAllNeighbors())
            return true;
    }
    return false;
}

bool Board::hasWon() {
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++) {
            if (board_[i][j] == 2048)
                return true;
        }
    return false;
}

void Board::moveDown() {
    isChanged_ = false;
    for(int j = 0; j<4; j++){
        for(int i = 3; i>0; i--){
            for (int k = i-1; k >= 0; k--) {
                if(board_[k][j]==0) {
                    continue;
                }
                if(board_[i][j] == 0){
                    std::swap(board_[i][j], board_[k][j]);
                    isChanged_ = true;
                    continue;
                }
                if (board_[i][j] == board_[k][j]) {
                    board_[i][j] *= 2;
                    board_[k][j] = 0;
                    score_+=board_[i][j];
                    isChanged_ = true;
                    break;
                }
                break;
            }

        }
    }
}

void Board::moveUp(){
    isChanged_ = false;
    for(int j = 0; j<4; j++){
        for(int i = 0; i<3; i++){
            for (int k = i+1; k <4; k++) {
                if(board_[k][j]==0) {
                    continue;
                }
                if(board_[i][j] == 0){
                    std::swap(board_[i][j], board_[k][j]);
                    isChanged_ = true;
                    continue;
                }
                if (board_[k][j] == board_[i][j]) {
                    board_[i][j] *= 2;
                    board_[k][j] = 0;
                    score_+=board_[i][j];
                    isChanged_ = true;
                }
                break;
            }

        }
    }
}

void Board::moveLeft() {
    isChanged_ = false;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<3; j++){
            for (int k = j+1; k<4; k++) {
                if(board_[i][k]==0) {
                    continue;
                }
                if(board_[i][j]==0){
                    std::swap(board_[i][j], board_[i][k]);
                    isChanged_ = true;
                    continue;
                }
                if (board_[i][k] == board_[i][j]) {
                    board_[i][j] *= 2;
                    board_[i][k] = 0;
                    score_+=board_[i][j];
                    isChanged_ = true;
                }
                break;
            }

        }
    }
}

void Board::moveRight() {
    isChanged_ = false;
    for(int i = 0; i<4; i++){
        for(int j = 3; j>0; j--){
            for (int k = j-1; k >= 0; k--) {
                if(board_[i][k]==0) {
                    continue;
                }
                if(board_[i][j]==0){
                    std::swap(board_[i][j], board_[i][k]);
                    isChanged_ = true;
                    continue;
                }
                if (board_[i][k] == board_[i][j]) {
                    board_[i][j] *= 2;
                    board_[i][k] = 0;
                    score_+=board_[i][j];
                    isChanged_ = true;
                }
                break;
            }

        }
    }
}

void Board::print(){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            labelDataBase[i][j]->Update(board_[i][j]);
        }
    }
}

