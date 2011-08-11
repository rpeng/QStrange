#ifndef STRANGESLIDER_H
#define STRANGESLIDER_H

#include <QSlider>

class StrangeSlider : public QSlider
{
    Q_OBJECT
public:
    explicit StrangeSlider(QWidget *parent = 0);

signals:
    void updateGenerator();

public slots:
    void syncValue(int value);

};

#endif // STRANGESLIDER_H
