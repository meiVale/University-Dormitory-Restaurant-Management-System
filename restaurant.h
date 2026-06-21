#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QString>

class Restaurant
{
    QString BreakfastMenu[10];
    QString LunchtMenu[10];
    QString DinnerMenu[10];

public:
    Restaurant();

    friend class RestaurantWorker;

    void setMenu(QString breakfast[10], QString lunch[10], QString dinner[10]) {
        for(int i = 0; i<10; i++) {
            BreakfastMenu[i] = breakfast[i];
            LunchtMenu[i] = lunch[i];
            DinnerMenu[i] = dinner[i];
        }
    }
};

#endif // RESTAURANT_H
