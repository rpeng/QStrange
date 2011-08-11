#include "strangespinner.h"

StrangeSpinner::StrangeSpinner(QWidget *parent = 0)
{
    this->setMaximum(3.00f);
    this->setMinimum(-3.00f);
    this->setWrapping(false);
    this->setSingleStep(0.03f);
}

void StrangeSpinner::syncValue(int value){
    this->setValue(static_cast<float>(value)/100.0f);
    emit updateGenerator();
}

StrangeSpinner::~StrangeSpinner(){

}
