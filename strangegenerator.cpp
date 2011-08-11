#include "strangegenerator.h"
#include <qmath.h>
#include <QDebug>

StrangeGenerator::StrangeGenerator()
{ 
    current = QPointF(0.1,0.1);

    a = -0.97;
    b = 2.88;
    c = 0.765;
    d = 0.744;

    /*
      -0.96692
      2.87988
      0.76514
      0.74473

      Other nice points to try:
      -1.4, 1.6, 1.0, 0.7
      1.1, -1.0, 1.0, 1.5
      1.6, -0.6, -1.2, 1.6
      1.7, 1.7, 0.06, 1.2
      1.3, 1.7, 0.5, 1.4
      1.5, -1.8, 1.6, 0.9
      */

    totalIterations = 300000;

    initialize();
}

QPointF StrangeGenerator::strangeFunction(QPointF input){
    float x = input.x();
    float y = input.y();

    float new_x = sin(y*b) + c*sin(x*b);
    float new_y = sin(x*a) + d*sin(y*a);

    return QPointF(new_x,new_y);
}

void StrangeGenerator::initialize(){
    // this function helps the attractor settle down to its position
    for (int i = 0; i < 100; i++) {

        current = strangeFunction(current);
        //qDebug() << current.x() << "," << current.y() << "\n";

    }
}

void StrangeGenerator::generate(){
    points.clear(); // regenerate
    for (int i = 0; i < totalIterations; i++){
        points.append(current);
        current = strangeFunction(current);
    }
}

StrangeGenerator::~StrangeGenerator(){
}
