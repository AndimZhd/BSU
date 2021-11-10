#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QRect rect, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("2048");
    setWindowIcon(QIcon("C:/Qt/Projects/2048_2/Image/2048.png"));
    board_ = new Board(rect);
    board_->setFocusPolicy(Qt::StrongFocus);
    toolWidget_ = new ToolWidget(rect);

    QWidget* w = new QWidget;
    QHBoxLayout* hLay = new QHBoxLayout(this);

    hLay->addWidget(board_);
    hLay->addWidget(toolWidget_);
    w->setLayout(hLay);
    setCentralWidget(w);

    connect(toolWidget_->newGame_, &QPushButton::clicked, this, &MainWindow::startTheGame);
    connect(toolWidget_->exit_, &QPushButton::clicked, this, &MainWindow::Close);
}

void MainWindow::startTheGame(){
    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
            board_->board_[i][j]=0;
    toolWidget_->score_->setText("0");
    //board_->focusWidget();
    //QKeyEvent* fakeEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_Down,Qt::KeyboardModifiers(), "1");
    //keyPressEvent(fakeEvent);
    board_->generateANumber();
    board_->generateANumber();
    board_->print();
}

void MainWindow::keyPressEvent(QKeyEvent * event){
    if(event->key()==Qt::Key_Up){
        board_->moveUp();
    }
    else if(event->key()==Qt::Key_Down){
        board_->moveDown();
    }
    else if(event->key()==Qt::Key_Left){
        board_->moveLeft();
    }
    else if(event->key()==Qt::Key_Right){
        board_->moveRight();
    }
    else if(event->key()==Qt::Key::Key_Escape){
        show();
        return;
    }
    else
        return;
    if(!board_->getStatus()){
                if(board_->hasWon()) {
                    print();
                    board_->setStatus(true);
                    QMessageBox::StandardButton reply = QMessageBox::question(this, "Congratulations!",  "You have won!!Continue playing?", QMessageBox::Yes|QMessageBox::No);
                    if(reply == QMessageBox::No)
                        close();
                }
            }
    if(board_->isChanged_)
       board_->generateANumber();
    if(board_->isOver()){
        print();
        QMessageBox::StandardButton reply = QMessageBox::question(this, "What a pity!",  "You have lost:( Do you want to play again?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::No)
           close();
        else{
            toolWidget_->score_->setText("0");
            startTheGame();
        }
    }
    print();
}

void MainWindow::Close(){
    close();
}

void MainWindow::print(){
    board_->print();
    toolWidget_->score_->setText(QString::number(board_->score_));
}

MainWindow::~MainWindow()
{
    delete ui;
}
