#include "fourthwindow.h"
#include "ui_fourthwindow.h"

#include <QString>
#include <QMessageBox>
#include <QFile>

fourthWindow::fourthWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fourthWindow)
{
    ui->setupUi(this);
}

fourthWindow::~fourthWindow()
{
    delete ui;
}

void fourthWindow::on_pushButton_saveMenu_clicked()
{
    QString breakfast = ui->lineEdit_breakfast->text();
    QString lunch = ui->lineEdit_lunch->text();
    QString dinner = ui->lineEdit_dinner->text();

    if(breakfast.isEmpty() || lunch.isEmpty() || dinner.isEmpty()) {
        QMessageBox::information(this, "Warning", "You left some menu empty");
    }

    // breakfast
    QFile file("data/breakfast.txt");

    if(file.open(QIODevice::WriteOnly)){
    QTextStream out(&file);
    out << breakfast;
    file.close();
    }
    else {
        QMessageBox::warning(this, "Error", "Failed to open file");
    }

    // lunch
    QFile file1("data/lunch.txt");

    if(file1.open(QIODevice::WriteOnly)){
    QTextStream out1(&file1);
    out1 << lunch;
    file1.close();
    }
    else {
        QMessageBox::warning(this, "Error", "Failed to open file");
    }

    // dinner
    QFile file2("data/dinner.txt");

    if(file2.open(QIODevice::WriteOnly)){
    QTextStream out2(&file2);
    out2 << dinner;
    file2.close();
    }
    else{
        QMessageBox::warning(this, "Error", "Failed to open file");
    }

    QMessageBox::information(this, "Done", "Menu updated");
}

