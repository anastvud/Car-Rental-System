#include "CarAttributes.h"

string Sedan::nameM() {
    return "Sedan";
}
string SUV::nameM() {
    return "SUV";
}

string ElectricEngine::nameE() {
    return "Electric";
}
string GasEngine::nameE() {
    return "Gas";
}

string Audi::nameB() {
    return "Audi";
}
int Audi::getPrice() {
    return price;
}
string Mitsubishi::nameB() {
    return "Mitsubishi";
}
int Mitsubishi::getPrice() {
    return price;
}
string Nissan::nameB() {
    return "Nissan";
}
int Nissan::getPrice() {
    return price;
}
string Volkswagen::nameB() {
    return "Volkswagen";
}
int Volkswagen::getPrice() {
    return price;
}