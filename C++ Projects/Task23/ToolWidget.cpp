#include "ToolWidget.h"
#include <QGridLayout>
#include <QSpacerItem>

ToolWidget::ToolWidget(QRect rect){
    setFixedSize(rect.height()*0.6, rect.height());
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);
    placeScoreLabels(rect);
    placeSpacers(rect);
    placeSpacers(rect);
    placeButtons(rect);
    placeSpacers(rect);
}

void ToolWidget::placeScoreLabels(QRect rect){
    QWidget* scoreWidget = new QWidget;
    scoreWidget->setFixedSize(rect.height()*0.6, rect.height()*0.25);
    QGridLayout* grid = new QGridLayout();
    grid->setColumnStretch(1, 0);

    QLabel* textOfScore = new QLabel("Your Score: ");
    textOfScore->setFixedSize(rect.height()*0.35, rect.height()*0.125);
    textOfScore->setStyleSheet("border-left: 2px solid white; border-top: 2px solid white; border-bottom:2px solid white; background-color: #b080f9; font: 45px bold italic 'Times New Roman'; color:white;");
    textOfScore->setAlignment(Qt::AlignCenter);
    grid->addWidget(textOfScore);

    score_ = new QLabel("0");
    //score_->setAlignment(Qt::AlignHCenter);
    score_->setFixedSize(rect.height()*0.25, rect.height()*0.125);
    score_->setStyleSheet("border-right: 2px solid white; border-top: 2px solid white; border-bottom:2px solid white; background-color:#b080f9; font: 45px bold italic 'Times New Roman'; color:white;");
    score_->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    grid->addWidget(score_);
    scoreWidget->setLayout(grid);
    this->layout()->addWidget(scoreWidget);
}

void ToolWidget::placeButtons(QRect rect){
    QWidget* buttons = new QWidget;
    buttons->setFixedSize(rect.height()*0.6, rect.height()*0.2);
    QGridLayout* grid = new QGridLayout;
    grid->setColumnStretch(1, 0);
    buttons->setLayout(grid);
    newGame_ = new QPushButton;
    newGame_->setFixedSize(rect.height()*0.25, rect.height()*0.132);
    newGame_->setText("New Game");
    newGame_->setStyleSheet("QPushButton{color:white; border-right: 2px solid black; border-top: 2px solid white; border-bottom:2px solid black; border-left: 2px solid white; background-color:#b080f9; font: 22px bold italic 'Times New Roman';}QPushButton::pressed{background-color:#7958ac;}");
    newGame_->setFocusPolicy(Qt::NoFocus);
    buttons->layout()->addWidget(newGame_);

    exit_ = new QPushButton;
    exit_->setFixedSize(rect.height()*0.25, rect.height()*0.132);
    exit_->setText("Exit");
    exit_->setStyleSheet("QPushButton{color:white; border-right: 2px solid black; border-top: 2px solid white; border-bottom:2px solid black; border-left: 2px solid white; background-color:#b080f9; font: 22px bold italic 'Times New Roman';}QPushButton::pressed{background-color:#7958ac;border-right: 2px solid white; border-top: 2px solid gray; border-bottom:2px solid white; border-left: 2px solid gray;}");
    exit_->setFocusPolicy(Qt::NoFocus);
    buttons->layout()->addWidget(exit_);
    layout()->addWidget(buttons);
}

void ToolWidget::placeSpacers(QRect rect){
    QSpacerItem* spacer = new QSpacerItem(rect.height()*0.5, rect.height()*0.15);
    layout()->addItem(spacer);
}
