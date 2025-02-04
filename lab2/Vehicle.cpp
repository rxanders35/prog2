#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(string make,
                 string model,
                 int year,
                 float price,
                 int mileage) : make(make),
                                model(model),
                                year(year),
                                price(price),
                                mileage(mileage) {}

Vehicle::Vehicle() : make("COP3503"),
                     model("Rust Bucket"),
                     year(1900), price(0.0f),
                     mileage(0) {}

void Vehicle::Display()
{
    cout << year
         << " "
         << make
         << " "
         << model
         << " $"
         << price
         << " "
         << mileage
         << endl;
}

string Vehicle::GetYearMakeModel()
{
    return year + " " + make + " " + model;
}

float Vehicle::GetPrice()
{
    return price;
}
#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(string make,
                 string model,
                 int year,
                 float price,
                 int mileage) : make(make),
                                model(model),
                                year(year),
                                price(price),
                                mileage(mileage)
{
}

Vehicle::Vehicle() : make("COP3503"),
                     model("Rust Bucket"),
                     year(1900), price(0.0f),
                     mileage(0) {}

void Vehicle::Display()
{
    cout << year
         << " "
         << make
         << " "
         << model
         << " "
         << price
         << " $"
         << mileage;
}

string Vehicle::GetYearMakeModel()
{
    return to_string(year) + " " + make + " " + model;
}

float Vehicle::GetPrice()
{
    return price;
}