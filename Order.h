#ifndef MAIN_CPP_ORDER_H
#define MAIN_CPP_ORDER_H

#include "Predirectives.h"
#include "Car.h"
#include "Interfaces.h"

class Order {
public:
    int order_id, days, sum = 0;
    string brand, model;
    char engine;
    Car* car;
    Order(Car* c, int d) {
        car = c;
        days = d;
        order_id = (rand() % 50) + 1;
        sum = d * car->brand->getPrice();
        brand = car->brand->nameB();
        model = car->model->nameM();
        engine = car->engine->nameE()[0];
    }
};

#endif //MAIN_CPP_ORDER_H