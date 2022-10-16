#ifndef MAIN_CPP_CAR_H
#define MAIN_CPP_CAR_H

#include "Predirectives.h"
#include "Interfaces.h"

class Car {
public:
    IBrand* brand;
    IModel* model;
    IEngine* engine;
    Car(IBrand* b, IModel* m, IEngine* e) : brand(b), model(m), engine(e) {};
};

#endif //MAIN_CPP_CAR_H