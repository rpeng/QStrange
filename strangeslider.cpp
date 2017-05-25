#include "strangeslider.h"
#include "qmath.h"

/*
 * We are making a slider to let users configure the max and min boundaries of
 * the scene.
 */
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
