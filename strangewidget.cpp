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

    strangeScene = new QPixmap(500,500);
    strangePainter = new QPainter(strangeScene);
    strangePainter->setPen(QColor(0,0,255,10));
    strangePainter->setRenderHint(QPainter::Antialiasing);

    mainLabel = new QLabel(this);
    mainLabel->setPixmap(*strangeScene);
    layout->addWidget(mainLabel);
    this->setLayout(layout);
}

void strangewidget::doPaint(){
    mainGen.generate();
    strangeScene->fill(Qt::black); // clear the pixmap
    drawAttractor(mainGen.points);
}

void strangewidget::drawAttractor(QList<QPointF> points){
    QPointF p;
    foreach (p,points){
        QPointF newp = p * 100; // amplify
        newp.rx() += 250; // center
        newp.ry() += 250;

        strangePainter->drawPoint(newp);
        //qDebug() << "drawing on " << newp.x() << "," << newp.y() << "\n";
    }
    mainLabel->setPixmap(*strangeScene);
    qDebug() << "painted!\n";
}

strangewidget::~strangewidget()
{
}
