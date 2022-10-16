#include "CarRentalSystem.h"
int choice = 5;

void CarRentalSystem::start() {
    cout << "\t\t\t\t\tWelcome to Car Rental System\n";
    cout << "\t\t\t\t\tYou can rent up to 5 cars!\n\n";
}
int CarRentalSystem::menu() {
    cout << "1 - add order\n2 - delete order\n3 - to print orders\n4 - to finish orders\n";
    int c;
    cin >> c;
    if (cin.fail()) {
        return menu();
    }
    switch (c) {
        case 1:
            addOrder();
            break;
        case 2:
            deleteCar();
            break;
        case 3:
            displayAll();
            break;
        case 4:
            finishOrder();
            break;
        default:
            cout << "Wrong number, please, try again\n";
            return menu();
            break;
    }
    cout << "\n";
    return menu();
}
int CarRentalSystem::addOrder() {
    if (choice == 0) {
        cout << "You can't take more than 5 cars\n";
        return menu();
    }
    int model, brand, engine, days;
    IBrand* b{};
    IModel* m{};
    IEngine* e{};
    cout << "Choose Sedan(1) or SUV(2): ";
    while (true) {
        cin >> model;
        if (model == 1 || model == 2) break;
        else {
            cout << "Wrong model, please choose again\n";
            cout << "Choose Sedan(1) or SUV(2): ";
        }
    }
    switch (model) {
        case 1:
            m = new Sedan();
            break;
        case 2:
            m = new SUV();
            break;
    }
    cout << "Choose from Audi(1), Nissan(2), Mitsubishi(3) or Volkswagen(4): ";
    while (true) {
        cin >> brand;
        if (brand == 1 || brand == 2 || brand == 3 || brand == 4) break;
        else {
            cout << "Wrong brand, please choose again\n";
            cout << "Choose from Audi(1), Nissan(2), Mitsubishi(3) or "
                    "Volkswagen(4): ";
        }
    }
    switch (brand) {
        case 1:
            b = new Audi();
            break;
        case 2:
            b = new Nissan();
            break;
        case 3:
            b = new Mitsubishi();
            break;
        case 4:
            b = new Volkswagen();
            break;
    }
    cout << "Choose Electric(1) or Gasoline(2) engine: ";
    while (true) {
        cin >> engine;
        if (engine == 1 || engine == 2) break;
        else {
            cout << "Wrong brand, please choose again\n";
            cout << "Choose Electric(1) or Gasoline(2) engine: ";
        }
    }
    switch (engine) {
        case 1:
            e = new ElectricEngine();
            break;
        case 2:
            e = new GasEngine();
            break;
    }
    cout << "For ___ days: ";
    while (true) {
        cin >> days;
        if (days > 0) break;
        else {
            cout << "Wrong number of days, please choose again\n";
            cout << "For ___ days: ";
        }
    }

    Car c1 = di::make_injector(
            di::bind<IEngine>.to<>(&*e),
            di::bind<IModel>.to<>(&*m),
            di::bind<IBrand>.to<>(&*b)
    ).create<Car>();
    Order o(&c1, days);
    cout << "ID" << "\tBrand" << "\t\tModel" << "\tEngine" << "\tDays"
         << "\tSum\n\n";
    cout << o.order_id << "\t" << o.brand << "\t\t"<< o.model
         << "\t\t" << o.engine << "\t\t" << o.days << "\t\t"
         << o.sum << "\n";
    v.push_back(o);
    choice--;
    return 0;
}
int CarRentalSystem::deleteCar() {
    if (choice == 5) {
        cout << "There is nothing to delete\n";
        return menu();
    }
    int del;
    cout << "Enter id of car you want to delete: ";
    cin >> del;
    for (auto i = 0; i < v.size(); i++) {
        if (v[i].order_id == del) {
            v.erase(v.begin() + i);
        }
    }
    choice++;
    return 0;
}
void CarRentalSystem::displayAll() {
    cout << "ID" << "\tBrand" << "\t\tModel" << "\tEngine" << "\tDays"
         << "\tSum\n\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].order_id << "\t" << v[i].brand << "\t\t"<< v[i].model
             << "\t\t" << v[i].engine << "\t\t" << v[i].days << "\t\t"
             << v[i].sum << "\n";
    }
}
int CarRentalSystem::finishOrder() {
    int sum_of_order = 0;
    for (int i = 0; i < v.size(); i++) {
        sum_of_order += v[i].sum;
    }
    cout << "You need to pay: " << sum_of_order << "\n";
    cout << "Do you want to start again? (1/0) ";
    int again;
    cin >> again;
    switch (again) {
        case 1:
            v.clear();
            return menu();
            break;
        case 0:
            cout << "Finishing the program...\n";
            exit(0);
            break;
    }
    return 0;
}