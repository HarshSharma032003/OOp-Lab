#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    double rentalPrice;

public:
    Vehicle() {}

    Vehicle(string brand, string model, int year, double rentalPrice)
        : brand(brand), model(model), year(year), rentalPrice(rentalPrice) {}

    virtual double getRentalCost(int days) {
        return days * rentalPrice;
    }
};

class Car : public Vehicle {
    int noOfDoors;

public:
    Car(string brand, string model, int year, double rentalPrice, int noOfDoors)
        : Vehicle(brand, model, year, rentalPrice), noOfDoors(noOfDoors) {}

    double getRentalCost(int days) override {
        double discount = (days > 7) ? 0.05 * rentalPrice : 0;
        return (days * (rentalPrice - discount));
    }
};

class Motorcycle : public Vehicle {
    int engineDisplacement;

public:
    Motorcycle() {}

    Motorcycle(string brand, string model, int year, double rentalPrice, int engineDisplacement)
        : Vehicle(brand, model, year, rentalPrice), engineDisplacement(engineDisplacement) {}

    double getRentalCost(int days) override {
        double discount = (days < 3) ? 0.1 * rentalPrice : 0;
        return (days * (rentalPrice - discount));
    }
};

class Bicycle : public Vehicle {
    string wireFrameMaterial;

public:
    Bicycle() {}

    Bicycle(string brand, string model, int year, double rentalPrice, string wireFrameMaterial)
        : Vehicle(brand, model, year, rentalPrice), wireFrameMaterial(wireFrameMaterial) {}

    double getRentalCost(int days) override {
        return 200 * days; // Consider making this dynamic if needed
    }
};

int main() {
    Vehicle v1("Bugatti", "Chiron", 2018, 30000);
    cout << "Rental cost of vehicle: " << v1.getRentalCost(10) << endl;

    Car c1("Maruti", "Swift", 2019, 3000, 4);
    cout << "Rental cost of car: " << c1.getRentalCost(9) << endl;

    Motorcycle m1("Honda", "Shine", 2024, 200, 125);
    cout << "Rental cost of motorcycle: " << m1.getRentalCost(2) << endl;

    Bicycle b1("Atlas", "Race", 2019, 100, "Steel");
    cout << "Rental cost of bicycle: " << b1.getRentalCost(4) << endl;

    return 0;
}
