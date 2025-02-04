#include "Dealership.h"
#include <iostream>

Dealership::Dealership(string name,
                       uint capacity) : name(name),
                                        capacity(capacity) {}

Dealership::Dealership() : name("Generic Dealership"),
                           capacity(0) {}

void Dealership::AddShowRoom(Showroom s)
{
    int numShowrooms = showrooms.size();

    if (numShowrooms == capacity)
    {
        cout << "Showroom is full! Cannot add another showroom!" << endl;
    }
    else
    {
        showrooms.push_back(s);
    }
}

float Dealership::GetAveragePrice()
{
    float price = 0.0f;
    int total = 0;
    for (Showroom s : showrooms)
    {
        for (Vehicle v : s.GetVehicleList())
        {
            price += v.GetPrice();
            total++;
        }
    }
    return price / total;
}

void Dealership::ShowInventory()
{
    if (showrooms.empty())
    {
        cout << name << " is empty!" << endl;
        return;
    }
    for (Showroom s : showrooms.name)
    {
        cout << "Vehicles in " << s << endl;
        for (Vehicle v : s.GetVehicleList())
        {
            v.Display();
            cout << " $" << v.GetPrice() << endl;
        }
    }

    cout << "Average car price: $" << GetAveragePrice() << endl;
}