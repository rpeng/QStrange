#include "strangespinner.h"

StrangeSpinner::StrangeSpinner(QWidget *parent = 0)
{
    this->setMaximum(300);
    this->setMinimum(-300);
    this->setWrapping(false);
}

void StrangeSpinner::syncValue(int value){
    this->setValue(value);
    emit updateGenerator();
}

StrangeSpinner::~StrangeSpinner(){

}
