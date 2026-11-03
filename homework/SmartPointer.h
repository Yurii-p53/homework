#pragma once
#include <iostream>

using namespace std;

template<class T>
class SmartPointer
{
    T* ptr;

public:

    SmartPointer(T* p = nullptr) : ptr(p) {}

    ~SmartPointer()
    {
        delete ptr;
    }

    SmartPointer(const SmartPointer& p) = delete;
    SmartPointer& operator=(const SmartPointer& p) = delete;

    SmartPointer(SmartPointer&& p)
    {
        ptr = p.ptr;
        p.ptr = nullptr;
    }

    SmartPointer& operator=(SmartPointer&& p)
    {
        if (this != &p)
        {
            delete ptr;

            ptr = p.ptr;
            p.ptr = nullptr;
        }

        return *this;
    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    T* get()
    {
        return ptr;
    }

    operator bool()
    {
        return ptr != nullptr;
    }

    void reset(T* p = nullptr)
    {
        if (ptr != p)
        {
            delete ptr;
            ptr = p;
        }
    }

    T* release()
    {
        T* p = ptr;
        ptr = nullptr;

        return p;
    }

    void swap(SmartPointer& p)
    {
        T* temp = ptr;
        ptr = p.ptr;
        p.ptr = temp;
    }
};