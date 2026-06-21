#include "thirdwindow.h"
#include "ui_thirdwindow.h"

#include "student.h"

#include <QFile>
#include <QMessageBox>

thirdWindow::thirdWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::thirdWindow)
{
    ui->setupUi(this);
}

thirdWindow::~thirdWindow()
{
    delete ui;
}


void thirdWindow::on_pushButton_add_clicked()
{
// check later how to check if provided data has alphabetics

    // dealing with classes:
    QString data1 = ui->lineEdit_newStudentId->text();
    QString data2 = ui->lineEdit_newStudentRoom->text();

    if(data1.isEmpty() || data2.isEmpty()){
        QMessageBox::warning(this, "Error", "Not enough information");
        return;
    }

    int id = data1.toInt();

    Student AddedStudent;
    AddedStudent.setID(id);
    AddedStudent.setRoom(data2);

    // UI:

    ui->listWidget_list->addItem(data1+','+data2);
    ui->lineEdit_newStudentId->clear();
    ui->lineEdit_newStudentRoom->clear();

    //file handling:

    QFile file("data/rooms.txt");
    if(file.open(QIODevice::Append)){

    // later add some if statement that throws an exception if file not opne

    QTextStream out(&file);

    out<<AddedStudent.getID()<<','<<AddedStudent.getRoom()<<'\n';

    file.close();
    }
    else {
        QMessageBox::warning(this, "Error", "Failed to open file");
    }

}


void thirdWindow::on_pushButton_remove_clicked()
{
    QListWidgetItem *item = ui->listWidget_list->currentItem();

    // checking if there was an item selected

    if(item == nullptr) {
        QMessageBox::information(this, "Error", "No Student Selected");
        return;
    }
    else {

        // file handling to remove a student

        QString lines[100]; // later fix to fit capacity of dorm
        QFile file("data/rooms.txt");
        int stop = 0;

        if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);

        int i = 0;

        while(!in.atEnd()){ // saving all the file in a qstring array;
            lines[i] = in.readLine();
            i++;
            stop = i;
        }
        file.close();
        }
        else {
            QMessageBox::warning(this, "Error", "Failed to open file");
        }

        if(file.open(QIODevice::WriteOnly)){

        QTextStream out(&file);

        for(int j = 0; j < stop; j++){
            QString current = ui->listWidget_list->currentItem()->text();

            if(lines[j]!=current)
            {
                out << lines[j] << '\n';
            }
        }
        }

        else {
            QMessageBox::warning(this, "Error", "Failed to open file");
        }

        delete item;

    }
    ui->listWidget_list->clearSelection();
}

void thirdWindow::on_pushButton_display_clicked()
{
    for(int i = 0; i < ui->listWidget_list->count(); i++)
    {
        ui->listWidget_list->item(i)->setHidden(false);
    }

    ui->listWidget_list->clear();
    QFile file("data/rooms.txt");

    if(file.open(QIODevice::ReadOnly)){

        if(file.size() == 0)
        {
            QMessageBox::warning(this, "Error", "No student in the list");
        }

        QTextStream in(&file);

        while(!in.atEnd()){
            ui->listWidget_list->addItem(in.readLine());
        }

        file.close();
    }

    else {
        QMessageBox::warning(this, "Error", "Failed to open file");
    }
}


void thirdWindow::on_pushButton_find_clicked()
{
    QString itemID = ui->lineEdit_StudentId_search->text();
    QString itemRoom = ui->lineEdit_room_search->text();

    for (int i = 0; i < ui->listWidget_list->count(); i++) {

        QString b = ui->listWidget_list->item(i)->text();

        if(!b.contains(itemID, Qt::CaseInsensitive) && !b.contains(itemRoom, Qt::CaseInsensitive)){
            ui->listWidget_list->item(i)->setHidden(true);
        }
    }

}

