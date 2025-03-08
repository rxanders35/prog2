#include <iostream>

class dynamicArray
{
private:
    double *arr;
    int maxCapacity;

public:
    dynamicArray(int size)
    {
        arr = new double[size];
        maxCapacity = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    double &operator[](int index)
    {
        return arr[index];
    }

    void display()
    {
        for (int i = 0; i < maxCapacity; i++)
        {
            std::cout << arr[i] << " ";
        }
    }

    int getMaxCapacity()
    {
        return maxCapacity;
    }
};
