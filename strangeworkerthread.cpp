#include "strangeworkerthread.h"
#include <QMutexLocker>
#include <QColor>
#include <QPainter>
#include <QPointF>

StrangeWorkerThread::StrangeWorkerThread(QObject *)
{
    strangeScene = new QPixmap(500,500);
    strangePainter = new QPainter(strangeScene);

    strangePainter->setPen(QColor(0,0,255,10));

    requiresUpdate = true;
    start(LowPriority);
}


StrangeWorkerThread::~StrangeWorkerThread(){
    this->terminate();
    delete strangeScene;
    delete strangePainter;
}

void StrangeWorkerThread::updateScene(){
    QMutexLocker locker(&mutex);
    requiresUpdate = true;
}

void StrangeWorkerThread::sendUpdate(float a, float b, float c, float d){
    QMutexLocker locker(&mutex);
    mainGen.setVars(a,b,c,d);
    requiresUpdate = true;
}

void StrangeWorkerThread::run(){
    forever{
        if (requiresUpdate){
            mainGen.generate();

            mutex.lock();
            strangeScene->fill(Qt::black); // clear the pixmat
            // draw attractor
            QPointF p;
            foreach (p, mainGen.points){
                QPointF newp = p * 100; // amplify
                newp.rx() += 250; // center
                newp.ry() += 250;

                strangePainter->drawPoint(newp);
            }
            requiresUpdate = false;
            mutex.unlock();
            emit sceneReady();
        }
        this->msleep(100);
    }
}

QPixmap* StrangeWorkerThread::getScene(){
    QMutexLocker locker(&mutex);
    return strangeScene;
}

