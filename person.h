#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{

    QString firstName;
    QString lastName;
    int id;

public:
    Person();
    void setName(const QString &FName, const QString &LName){
        firstName = FName; lastName = LName;}

    void setID(int ID){id = ID;}
    QString getName() const { return (lastName+" "+firstName);}
    int getID() const { return id;}

};

#endif // PERSON_H
