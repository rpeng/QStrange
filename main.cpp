#include <QtGui/QApplication>
#include "strangegenerator.h"
#include "strangewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    strangeWindow w;
    w.show();

    return a.exec();

    //StrangeGenerator app;

}
