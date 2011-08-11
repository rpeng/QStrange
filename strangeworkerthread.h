#ifndef STRANGEWORKERTHREAD_H
#define STRANGEWORKERTHREAD_H

#include <QThread>
#include <QPixmap>
#include <QMutex>
#include <QPainter>

#include "strangegenerator.h"

class StrangeWorkerThread : public QThread
{
    Q_OBJECT

protected:
    QPixmap *strangeScene;
    QPainter *strangePainter;
    StrangeGenerator mainGen;
    bool requiresUpdate;

signals:
    void sceneReady();

public:
    QMutex mutex;
    QPixmap* getScene();
    virtual void updateScene();
    virtual void run();
    virtual void sendUpdate(float,float,float,float);
    StrangeWorkerThread(QObject *parent = 0);
    ~StrangeWorkerThread();
};

#endif // STRANGEWORKERTHREAD_H
