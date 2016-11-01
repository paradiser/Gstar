#include "renderWindow.h"
#include "ui_renderWindow.h"

renderWindow::renderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::renderWindow)
{
    ui->setupUi(this);
}

renderWindow::~renderWindow()
{
    delete ui;
}
