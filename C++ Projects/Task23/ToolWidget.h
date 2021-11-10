#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class ToolWidget:public QWidget{
    QRect rect_;
    friend class MainWindow;
    QLabel* score_;
    QPushButton* newGame_;
    QPushButton* exit_;
public:

    ToolWidget(QRect);
    void placeScoreLabels(QRect);
    void placeButtons(QRect);
    void placeSpacers(QRect);
};

#endif // TOOLWIDGET_H
