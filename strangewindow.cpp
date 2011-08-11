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

}

void strangeWindow::paintPressed(){
    mainWidget->doPaint();
}

strangeWindow::~strangeWindow()
{
    delete ui;
}
