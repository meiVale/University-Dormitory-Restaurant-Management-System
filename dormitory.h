#ifndef DORMITORY_H
#define DORMITORY_H

#include "restaurant.h"
#include "room.h"

#include <QString>

class Dormitory
{
    int capacity;
    Restaurant restau;
    Room *rooms;

public:
    Dormitory();

    friend class DormAdministrator;

    void displayRoomList();

};

#endif // DORMITORY_H
