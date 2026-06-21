#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

#include <QString>

class Student : public Person
{
    QString degree;
    int academicYear;
    QString room;

public:

    Student();
    QString getDegree() const {return degree;}
    int getAcademicYear() const {return academicYear;}
    QString getRoom() const {return room;}

    void setDegree(const QString &Degree) {degree = Degree;}
    void setAcademicYear(int year) {academicYear = year;}
    void setRoom(QString Room) {room = Room;}
};

#endif // STUDENT_H
