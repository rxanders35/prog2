#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include "Showroom.h"
#include "Vehicle.h"
#include <string>
#include <vector>

class Dealership
{
private:
    string name;
    uint capacity;
    vector<Showroom> showrooms;

public:
    Dealership();
    Dealership(string name, uint capacity);

    void AddShowRoom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();
};
#endif