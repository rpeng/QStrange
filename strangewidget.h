#ifndef STRANGEWIDGET_H
#define STRANGEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QList>
#include <QPointF>
#include <QLabel>

#include "strangegenerator.h"


class strangewidget : public QWidget
{
    Q_OBJECT
public:
    explicit strangewidget(QWidget *parent = 0);
    ~strangewidget();

    virtual void drawAttractor(QList<QPointF> points);
    virtual void doPaint();

private:
    QPixmap *strangeScene;
    QPainter *strangePainter;
    QLabel *mainLabel;
    StrangeGenerator mainGen;
};

#endif // STRANGEWIDGET_H
