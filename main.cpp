#include "Predirectives.h"
#include "CarRentalSystem.h"

int main() {
    srand((unsigned)time(0));
    CarRentalSystem r;
    r.start();
    r.menu();
}