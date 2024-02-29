#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QListWidgetItem>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_add_button_clicked()
{
    QString str = ui->lineEdit->text();
    if(str == ""){
        QMessageBox::critical(this,"Error input","Empty input");
    }else{
        ui->listWidget->addItem(str);
    }
}




void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "message", "Do you want to delete?",QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes){
        delete item;
    }
}

