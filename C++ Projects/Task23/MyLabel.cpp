#include "MyLabel.h"
#include <QStyle>

MyLabel::MyLabel(QString str, QRect rect):QLabel(str){
    rect_ = rect;
    setFixedSize(rect.height()/5, rect.height()/5);
    setAlignment(Qt::AlignCenter);
    //setStyleSheet("background-color: gray; font: 60px bold italic 'Times New Roman'");
}

void MyLabel::Update(int value){
    QString str = QString::number(value);
    if(value)
        setText(str);
    else
        setText("");
    setStyleSheet("background-color:"+getColor(str)+"; font: 60px bold italic 'Times New Roman'");
}

QString MyLabel::getColor(QString str){
    switch(str.toInt()){
       case 0: return "white";
       case 2: return "#93f1ff";
       case 4: return "#90d3ff";
       case 8: return "#8cbcfd";
       case 16: return "#8797f9";
       case 32: return "#9b54f3";
       case 64: return "#b080f9";
       case 128: return "#c354f3";
       case 256: return "#ea72c1";
       case 512: return "#f45a84";
       case 1024: return "#fa3f4d";
       case 2048: return "#fa1f1f";
    }
}
