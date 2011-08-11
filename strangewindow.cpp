#include "strangewindow.h"
#include "ui_strangewindow.h"

strangeWindow::strangeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::strangeWindow)
{
    ui->setupUi(this);
    this->connect(ui->paintButton,SIGNAL(clicked()),SLOT(paintPressed()));
    mainWidget = new strangewidget();
    ui->mainLayout->addWidget(mainWidget);

    // extra ui settings
    ui->slider_a->setValue(-97);
    ui->slider_b->setValue(288);
    ui->slider_c->setValue(76);
    ui->slider_d->setValue(74);

    // extra connects
    this->connect(ui->slider_a,SIGNAL(updateGenerator()),SLOT(sendUpdate()));
    this->connect(ui->slider_b,SIGNAL(updateGenerator()),SLOT(sendUpdate()));
    this->connect(ui->slider_c,SIGNAL(updateGenerator()),SLOT(sendUpdate()));
    this->connect(ui->slider_d,SIGNAL(updateGenerator()),SLOT(sendUpdate()));
    this->connect(ui->spin_a,SIGNAL(updateGenerator()),SLOT(sendUpdate()));
    this->connect(ui->spin_b,SIGNAL(updateGenerator()),SLOT(sendUpdate()));
    this->connect(ui->spin_c,SIGNAL(updateGenerator()),SLOT(sendUpdate()));
    this->connect(ui->spin_d,SIGNAL(updateGenerator()),SLOT(sendUpdate()));

}

void strangeWindow::paintPressed(){
    //
}

void strangeWindow::sendUpdate(){
    // propogate
    double a = static_cast<double>(ui->spin_a->value())/100.0f;
    double b = static_cast<double>(ui->spin_b->value())/100.0f;
    double c = static_cast<double>(ui->spin_c->value())/100.0f;
    double d = static_cast<double>(ui->spin_d->value())/100.0f;

    mainWidget->sendUpdate(a,b,c,d);
}

strangeWindow::~strangeWindow()
{
    delete ui;
}
