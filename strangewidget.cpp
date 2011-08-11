#include "strangewidget.h"

#include <QPointF>
#include <QPen>
#include <QBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QColor>

strangewidget::strangewidget(QWidget *parent) :
    QWidget(parent)
{
    // inits
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);

    mainLabel = new QLabel(this);
    layout->addWidget(mainLabel);
    this->setLayout(layout);

    // extra ui settings
    this->connect(&mainThread,SIGNAL(sceneReady()),SLOT(drawAttractor()));
}

void strangewidget::sendUpdate(float a, float b, float c, float d){
   // propogate once more
    mainThread.sendUpdate(a,b,c,d);
}

void strangewidget::drawAttractor(){
    mainLabel->setPixmap(*(mainThread.getScene()));
    qDebug() << "painted!\n";
}

strangewidget::~strangewidget()
{
}
