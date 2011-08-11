#ifndef STRANGEGENERATOR_H
#define STRANGEGENERATOR_H

#include <QPointF>
#include <QList>

class StrangeGenerator
{

protected:
    QPointF current; // current point
    float a, b, c, d; // coefficients

public:

    int totalIterations; // how many times to loop through to draw a dot

    virtual QPointF strangeFunction(QPointF); // attractor function
    virtual void initialize(); // allows the attractor to settle
    virtual void generate(); // generates a bunch of points

    QList<QPointF> points; // a list of points
    StrangeGenerator();
    ~StrangeGenerator();
};

#endif // STRANGEGENERATOR_H
