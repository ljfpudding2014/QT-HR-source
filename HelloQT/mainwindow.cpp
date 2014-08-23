#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OKButton_clicked()
{

   QString strUserName = ui->usernameEdit->text();
   QString strPassword = ui->passwordEdit->text();


   MainWindow::close();

}

void MainWindow::on_usernameEdit_returnPressed()
{



}
