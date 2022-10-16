#ifndef MAIN_CPP_CARRENTALSYSTEM_H
#define MAIN_CPP_CARRENTALSYSTEM_H

#include "Predirectives.h"
#include "CarAttributes.h"
#include "CarRentalSystem.h"
#include "Car.h"
#include "Order.h"
#include "Interfaces.h"

class CarRentalSystem {
public:
    vector<Order> v;
    void start();
    int menu();
    int addOrder();
    int deleteCar();
    void displayAll();
    int finishOrder();
};

#endif //MAIN_CPP_CARRENTALSYSTEM_H