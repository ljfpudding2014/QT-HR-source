#include "hrmainwindow.h"
#include "ui_hrmainwindow.h"

HRMainWindow::HRMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HRMainWindow)
{
    ui->setupUi(this);
}

HRMainWindow::~HRMainWindow()
{
    delete ui;
}
