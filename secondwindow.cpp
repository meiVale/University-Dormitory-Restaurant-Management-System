#include "secondwindow.h"
#include "ui_secondwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>


SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}
void SecondWindow::on_pushButton_show_clicked()
{
    QFile file("data/breakfast.txt");

    if(file.open(QIODevice::ReadOnly)){
    QTextStream in(&file);
    ui->textBrowser_breakfast->setText(in.readLine());
    file.close();
    }
    else {
        QMessageBox::warning(this, "Error", "Failed to open file");
    }

    QFile file1("data/lunch.txt");

    if(file1.open(QIODevice::ReadOnly)){
    QTextStream in1(&file1);
    ui->textBrowser_lunch->setText(in1.readLine());
    file1.close();
    }
    else {
        QMessageBox::warning(this, "Error", "Failed to open file");
    }

    QFile file2("data/dinner.txt");

    if(file2.open(QIODevice::ReadOnly)){
    QTextStream in2(&file2);
    ui->textBrowser_dinner->setText(in2.readLine());
    file2.close();
    }
    else {
        QMessageBox::warning(this, "Error", "Failed to open file");
    }
}

