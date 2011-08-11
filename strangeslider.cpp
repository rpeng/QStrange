#include "strangeslider.h"
#include "qmath.h"

StrangeSlider::StrangeSlider(QWidget *parent) :
    QSlider(parent)
{
    this->setMaximum(300);
    this->setMinimum(-300);
}

void StrangeSlider::syncValue(double value){
    this->setValue(floor(value * 100.0f));
    emit updateGenerator();
}
