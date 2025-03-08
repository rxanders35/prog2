#ifndef ABS_H
#define ABS_H
#include <stdexcept>

typedef unsigned int uint;

static const float SCALE_FACTOR = 2.0f;

template <typename T>
class ABQ
{
private:
    uint cap;
    uint curr_size;
    T *arr;
public:
    ABQ()
    {
       cap = 1;
       curr_size = 0;
       arr = new T[cap];
    }

    ABQ(int capacity)
    {
       curr_size = 0;
       cap = capacity;
       arr = new T[cap];
    }

    ABQ(const ABQ &d)
    {
        curr_size = d.curr_size;
        cap = d.cap;
        arr = new T[cap];
        for (uint i = 0; i < curr_size; i++)
        {
            arr[i] = d.arr[i];
        }

    }

    ABQ &operator=(const ABQ &d)
    {
        if (this == &d)
        {
            return *this;
        }

        delete[] arr;
        curr_size = d.curr_size;
        cap = d.cap;
        arr = new T[cap];

        for(uint i = 0; i < curr_size; i++)
        {
            arr[i] = d.arr[i];
        } 

        return *this;

    }

    ~ABQ()
    {
        delete[] arr; 
    }

    void enqueue(T data)
    {
        if (curr_size == cap) 
        {
            uint r_cap = static_cast<uint>(cap * SCALE_FACTOR);
            T* temp = new T[r_cap];
            for (uint i = 0; i < curr_size; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            cap = r_cap;
        }
        arr[curr_size++] = data;
    }

    T dequeue()
    {
        if (curr_size == 0)
            throw std::runtime_error("Queue is empty");

        T res = arr[0];

        for (uint i = 0; i < curr_size - 1; i++)
            arr[i] = arr[i + 1];
        curr_size--;

        if (curr_size == 0)
        {
            delete[] arr;
            cap = 1;
            arr = new T[cap];
        }
        else if (static_cast<float>(curr_size) / cap < 1.0f / SCALE_FACTOR)
        {
            uint new_cap = static_cast<uint>(cap / SCALE_FACTOR);
            if (new_cap < 1)
                new_cap = 1;
            T* temp = new T[new_cap];
            for (uint i = 0; i < curr_size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            cap = new_cap;
        }
        return res;
    }

    T peek()
    {
        if (curr_size == 0)
        {
            throw std::runtime_error("Queue is empty");
        }
        return arr[0];
    }

    uint getSize()
    {
        return curr_size;
    }

    uint getMaxCapacity()
    {
        return cap;
    }

    T* getData()
    {
        return arr;
    }
};

#endif
