#ifndef ABS_H
#define ABS_H
#include <iostream>
#include <stdexcept>

typedef unsigned int uint;
//I like uint but my clang-based lsp has no typedef for it unlike gcc

static const float SCALE_FACTOR = 2.0f;

template <typename T>
class ABS
{
private:
    uint cap;
    uint curr_size;
    T *arr;
public:
    ABS()
    {
        cap = 1;
        curr_size = 0;
        arr = new T[cap];
    }

    ABS(int capacity)
    {
        curr_size = 0;
        cap = capacity;
        arr = new T[cap];
    }

    ABS(const ABS &d)
    {
        curr_size = d.curr_size;
        cap = d.cap;
        arr = new T[cap];
        for (uint i = 0; i < curr_size; i++)
        {
            arr[i] = d.arr[i];
        }

    }

    ABS &operator=(const ABS &d)
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

    ~ABS()
    {
       delete[] arr; 
    }ABS(const ABS &d)
    {
        curr_size = d.curr_size;
        cap = d.cap;
        arr = new T[cap];
        for (uint i = 0; i < curr_size; i++)
        {
            arr[i] = d.arr[i];
        }

    }

    ABS &operator=(const ABS &d)
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

    ~ABS()
    {
       delete[] arr; 
    }AABS(const ABS &d)
    {
        curr_size = d.curr_size;
        cap = d.cap;
        arr = new T[cap];
        for (uint i = 0; i < curr_size; i++)
        {
            arr[i] = d.arr[i];
        }

    }

    ABS &operator=(const ABS &d)
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

    ~ABS()
    {
       delete[] arr; 
    }BS(const ABS &d)
    {
        curr_size = d.curr_size;
        cap = d.cap;
        arr = new T[cap];
        for (uint i = 0; i < curr_size; i++)
        {
            arr[i] = d.arr[i];
        }

    }

    ABS &operator=(const ABS &d)
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

    ~ABS()
    {
       delete[] arr; 
    }

    void push(T data)
    {
        if (curr_size == cap)
        {
            uint r_cap = static_cast<uint>(cap * SCALE_FACTOR);
            T *temp = new T[r_cap];

            for(uint i = 0; i < cap; i++)
            {
                temp[i] = arr[i];
            }

            delete[] arr;

            arr = temp;
            cap = r_cap;
        }
        arr[curr_size++] = data;
    }

    T pop()
    {
        if (curr_size == 0)
            throw std::runtime_error("Stack is empty");
        T res = arr[curr_size - 1];
        curr_size--;

        if (curr_size == 0)
        {
            delete[] arr;
            cap = 1;
            arr = new T[cap];
        }
        else if (static_cast<float>(curr_size) / cap <= 1.0f / SCALE_FACTOR)
        {
            uint r_cap = static_cast<uint>(cap / SCALE_FACTOR);
            if (r_cap < 1)
                r_cap = 1;
            T* temp = new T[r_cap];
            for (uint i = 0; i < curr_size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            cap = r_cap;
        }
        return res;
    } 

    T peek()
    {
        if (curr_size == 0)
        {
            throw std::runtime_error("Stack is empty");
        }
        T val = arr[curr_size-1];
        return val;
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

