#include "strangeslider.h"
#include "qmath.h"

StrangeSlider::StrangeSlider(QWidget *parent) :
    QSlider(parent)
{
    this->setMaximum(300);
    this->setMinimum(-300);
}

void StrangeSlider::syncValue(int value){
    this->setValue(value);
    emit updateGenerator();
}
