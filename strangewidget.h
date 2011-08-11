#ifndef STRANGEWIDGET_H
#define STRANGEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QList>
#include <QPointF>
#include <QLabel>

#include "strangegenerator.h"
#include "strangeworkerthread.h"


class strangewidget : public QWidget
{
    Q_OBJECT

public slots:
    virtual void drawAttractor();

public:
    explicit strangewidget(QWidget *parent = 0);
    ~strangewidget();

    virtual void sendUpdate(float,float,float,float);

private:
    StrangeWorkerThread mainThread;
    QLabel *mainLabel;
};

#endif // STRANGEWIDGET_H
