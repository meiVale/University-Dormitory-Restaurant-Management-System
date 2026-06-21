#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPixmap>

#include "secondwindow.h"
#include "thirdwindow.h"
#include "fourthwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OOP_Project)
{
    ui->setupUi(this);
    move(300,1);

    QPixmap pix(":/images/images/mond.png");
    ui->label_picture->setPixmap(pix.scaled(180,180,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SecondWindow s;
    s.setModal(true);
    s.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    thirdWindow k;
    k.setModal(true);
    k.exec();
}



void MainWindow::on_pushButton_3_clicked()
{
    fourthWindow t;
    t.setModal(true);
    t.exec();
}

