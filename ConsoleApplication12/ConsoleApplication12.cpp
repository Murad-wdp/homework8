#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Engine {
public:
    string engineNo;
    string company;
    double volume;

    Engine(string no, string comp, double vol) : engineNo(no), company(comp), volume(vol) {}
};


class Vehicle {
protected:
    int id;
    string model;
    string vendor;
    Engine engine;

public:
    Vehicle(int id, string model, string vendor, Engine engine)
        : id(id), model(model), vendor(vendor), engine(engine) {}

    virtual void Show() = 0; 
};


class Car : public Vehicle {
private:
    bool hasSpoiler;

public:
    Car(int id, string model, string vendor, Engine engine, bool spoiler)
        : Vehicle(id, model, vendor, engine), hasSpoiler(spoiler) {}

    void Show() override {
        cout << "Car - ID: " << id
            << ", Model: " << model
            << ", Vendor: " << vendor
            << ", Has Spoiler: " << (hasSpoiler ? "Yes" : "No")
            << ", Engine No: " << engine.engineNo
            << ", Company: " << engine.company
            << ", Volume: " << engine.volume << endl;
    }
};


class Ship : public Vehicle {
private:
    bool hasSail;

public:
    Ship(int id, string model, string vendor, Engine engine, bool sail)
        : Vehicle(id, model, vendor, engine), hasSail(sail) {}

    void Show() override {
        cout << "Ship - ID: " << id
            << ", Model: " << model
            << ", Vendor: " << vendor
            << ", Has Sail: " << (hasSail ? "Yes" : "No")
            << ", Engine No: " << engine.engineNo
            << ", Company: " << engine.company
            << ", Volume: " << engine.volume << endl;
    }
};


class Airplane : public Vehicle {
private:
    int engineCount;
    int passengersCapacity;

public:
    Airplane(int id, string model, string vendor, Engine engine, int count, int capacity)
        : Vehicle(id, model, vendor, engine), engineCount(count), passengersCapacity(capacity) {}

    void Show() override {
        cout << "Airplane - ID: " << id
            << ", Model: " << model
            << ", Vendor: " << vendor
            << ", Engine Count: " << engineCount
            << ", Passengers Capacity: " << passengersCapacity
            << ", Engine No: " << engine.engineNo
            << ", Company: " << engine.company
            << ", Volume: " << engine.volume << endl;
    }
};


class VehicleDepot {
private:
    stack<Car> cars;
    stack<Ship> ships;
    stack<Airplane> airplanes;

public:
    void AddCar(const Car& car) { cars.push(car); }
    void AddShip(const Ship& ship) { ships.push(ship); }
    void AddAirplane(const Airplane& airplane) { airplanes.push(airplane); }

    void ShowAllVehicles() {
        cout << "Cars:" << endl;
        stack<Car> tempCars = cars; 
        while (!tempCars.empty()) {
            tempCars.top().Show();
            tempCars.pop();
        }

        cout << "\nShips:" << endl;
        stack<Ship> tempShips = ships; 
        while (!tempShips.empty()) {
            tempShips.top().Show();
            tempShips.pop();
        }

        cout << "\nAirplanes:" << endl;
        stack<Airplane> tempAirplanes = airplanes; 
        while (!tempAirplanes.empty()) {
            tempAirplanes.top().Show();
            tempAirplanes.pop();
        }
    }
};

int main() {
    Engine carEngine("E123", "Tesla", 2.0);
    Car car(1, "Model S", "Tesla", carEngine, true);

    Engine shipEngine("E456", "Ship Engines Inc.", 5.0);
    Ship ship(2, "Titanic", "White Star Line", shipEngine, false);

    Engine airplaneEngine("E789", "Aircraft Engines Ltd.", 10.0);
    Airplane airplane(3, "Boeing 747", "Boeing", airplaneEngine, 4, 660);

    VehicleDepot depot;
    depot.AddCar(car);
    depot.AddShip(ship);
    depot.AddAirplane(airplane);

    depot.ShowAllVehicles();

    return 0;
}
