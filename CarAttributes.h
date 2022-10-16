#ifndef MAIN_CPP_CARATTRIBUTES_H
#define MAIN_CPP_CARATTRIBUTES_H

#include "Predirectives.h"
#include "Interfaces.h"

class Sedan : public IModel {
public:
    string nameM() override;
};
class SUV : public IModel {
public:
    string nameM() override;
};

class ElectricEngine : public IEngine {
public:
    string nameE() override;
};
class GasEngine : public IEngine {
public:
    string nameE() override;
};

class Audi : public IBrand {
private:
    int price = 35;
public:
    string nameB() override;
    int getPrice();
};
class Mitsubishi : public IBrand {
private:
    int price = 30;
public:
    string nameB() override;
    int getPrice();
};
class Nissan : public IBrand {
private:
    int price = 20;
public:
    string nameB() override;
    int getPrice();
};
class Volkswagen : public IBrand {
private:
    int price = 25;
public:
    string nameB() override;
    int getPrice();
};

#endif //MAIN_CPP_CARATTRIBUTES_H