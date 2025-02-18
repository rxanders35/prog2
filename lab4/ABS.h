#include <iostream>


typedef unsigned int uint; //I like uint

template <typename T>
class ABS
{
private:
    static const int MAX_CAP = 1;
    int capacity = 0;
    T *arr;
    uint size;

public:
    ABS() : capacity(MAX_CAP)
    {
        T arr = new T[capacity];
    }

    ABS(int capacity) : capacity(capacity > MAX_CAP ? MAX_CAP : capacity)
    {
        T arr = new T[this->capacity];
    }

    ABS(const ABS &d) : capacity(d.capacity), size(d.size)
    {
        T arr = new T[capacity];
        std::copy(d.arr, d.arr+ size, arr);
    }

    ~ABS()
    {
        delete[] arr;
    }

    ABS &operator=(const ABS &d)
    {
        if (this != &d)
        {
            delete[] arr;
            capacity = d.capacity;
            arr = new T[capacity];
            size = d.size;
            for (int i = 0; i < size; i++)
            {
                arr[i] = d.arr[i];
            }
        }
        return *this;
    }    

    void push(T data)
    {
        arr[size] = data;
        size++;
    }

    T pop()
    {
        if (size == 0)
        {
            throw std::runtime_error("Stack is empty");
        }
        size--;
        return arr[size];

    }

    T peek()
    {
        

    }
    uint getSize();
    uint getMaxCapacity();
    T* getData();
};
