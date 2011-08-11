#ifndef STRANGEWINDOW_H
#define STRANGEWINDOW_H

#include <QMainWindow>

#include <strangewidget.h>

namespace Ui {
    class strangeWindow;
}

class strangeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit strangeWindow(QWidget *parent = 0);
    ~strangeWindow();

public slots:
    virtual void paintPressed();
    virtual void sendUpdate();

private:
    Ui::strangeWindow *ui;
    strangewidget *mainWidget;
};

#endif // STRANGEWINDOW_H
