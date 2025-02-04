#ifndef SHOWROOM_H
#define SHOWROOM_H
#include "Vehicle.h"
#include <string>
#include <vector>
using namespace std;

class Showroom
{
private:
    string name;
    vector<Vehicle> vehicles;
    uint capacity;

public:
    Showroom();
    Showroom(string name, uint capacity);

    vector<Vehicle> GetVehicleList();
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
};

#endif