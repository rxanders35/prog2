#include "Showroom.h"
#include <iostream>

Showroom::Showroom(string name,
                   uint capacity) : name(name),
                                    capacity(capacity) {}

Showroom::Showroom() : name("Unnamed Showroom"),
                       capacity(0) {}

vector<Vehicle> Showroom::GetVehicleList()
{
    return vehicles;
}

void Showroom::AddVehicle(Vehicle v)
{
    int numVehicles = vehicles.size();

    if (numVehicles == capacity)
    {
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel();
    }
    else
    {
        vehicles.push_back(v);
    }
}

void Showroom::ShowInventory()
{
    if (vehicles.empty())
    {
        cout << name << " is empty!" << endl;
        return;
    }
    cout << "Vehicles in " << name << endl;
    for (Vehicle v : vehicles)
    {
        v.Display();
    }
}

float Showroom::GetInventoryValue()
{
    float sum = 0.0f;
    for (Vehicle v : vehicles)
    {
        sum += v.GetPrice();
    }
    return sum;
}