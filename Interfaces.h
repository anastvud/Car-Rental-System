#ifndef MAIN_CPP_INTERFACES_H
#define MAIN_CPP_INTERFACES_H

#include "Predirectives.h"
class IEngine {
public:
    virtual string nameE() = 0;
    virtual ~IEngine() {}
};
class IBrand {
public:
    virtual string nameB() = 0;
    virtual int getPrice() = 0;
    virtual ~IBrand() {}
};
class IModel {
public:
    virtual string nameM() = 0;
    virtual ~IModel() {}
};

#endif //MAIN_CPP_INTERFACES_H