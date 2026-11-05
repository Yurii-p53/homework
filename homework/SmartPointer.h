#pragma once

#include <iostream>

using namespace std;

template<class T>
class SharedPointer
{
    T* ptr;
    int* count;

public:

    SharedPointer(T* p = nullptr)
    {
        ptr = p;

        if (ptr != nullptr)
            count = new int(1);
        else
            count = nullptr;
    }

    ~SharedPointer()
    {
        if (count != nullptr)
        {
            (*count)--;

            if (*count == 0)
            {
                delete ptr;
                delete count;
            }
        }
    }

    SharedPointer(const SharedPointer& p)
    {
        ptr = p.ptr;
        count = p.count;

        if (count != nullptr)
            (*count)++;
    }

    SharedPointer& operator=(const SharedPointer& p)
    {
        if (this != &p)
        {
            if (count != nullptr)
            {
                (*count)--;

                if (*count == 0)
                {
                    delete ptr;
                    delete count;
                }
            }

            ptr = p.ptr;
            count = p.count;

            if (count != nullptr)
                (*count)++;
        }

        return *this;
    }

    SharedPointer(SharedPointer&& p) noexcept
    {
        ptr = p.ptr;
        count = p.count;

        p.ptr = nullptr;
        p.count = nullptr;
    }

    SharedPointer& operator=(SharedPointer&& p) noexcept
    {
        if (this != &p)
        {
            if (count != nullptr)
            {
                (*count)--;

                if (*count == 0)
                {
                    delete ptr;
                    delete count;
                }
            }

            ptr = p.ptr;
            count = p.count;

            p.ptr = nullptr;
            p.count = nullptr;
        }

        return *this;
    }

    T& operator*()
    {
        if (ptr == nullptr)
            throw exception("pointer is empty");

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

    int getCount()
    {
        if (count == nullptr)
            return 0;

        return *count;
    }

    operator bool()
    {
        return ptr != nullptr;
    }

    void reset(T* p = nullptr)
    {
        if (ptr != p)
        {
            if (count != nullptr)
            {
                (*count)--();

                if (*count == 0)
                {
                    delete ptr;
                    delete count;
                }
            }

            ptr = p;

            if (ptr != nullptr)
                count = new int(1);
            else
                count = nullptr;
        }
    }

    void swap(SharedPointer& p)
    {
        T* temp = ptr;
        ptr = p.ptr;
        p.ptr = temp;

        int* tempCount = count;
        count = p.count;
        p.count = tempCount;
    }
};