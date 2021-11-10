#ifndef MYLABEL_H
#define MYLABEL_H

#include<QLabel>
#include <QRect>

class MyLabel:public QLabel{
public:
    QRect rect_;
    MyLabel(QString, QRect);
    void Update(int);
    QString getColor(QString);
};


#endif // MYLABEL_H
