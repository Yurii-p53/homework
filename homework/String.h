#pragma once
#include<iostream>

using namespace std;

class String {
    char* str;
    int size;
    static int count;


public:
    String() : String(80) {
        cout << "constructor 0\n";
    }

    String(int s) {
        size = s;
        str = new char[size + 1];
        str[0] = '\0';
        count++;
        cout << "constructor int\n";
    }

    String(const char* txt) {
        size = strlen(txt);
        str = new char[size + 1];
        strcpy(str, txt);
        count++;
        cout << "constructor char\n";
    }

    String(const String& obj) {
        size = obj.size;
        str = new char[size + 1];
        strcpy(str, obj.str);
        cout << "copydestr\n";
    }

    String& operator=(const String& obj) {
        if (this == &obj)
        {
            return *this;
        }

        delete[] str;
        size = obj.size;
        str = new char[size + 1];
        strcpy(str, obj.str);

        return *this;
    }

    String& operator=(const char* txt) {
        delete[] str;
        size = strlen(txt);
        str = new char[size + 1];
        strcpy(str, txt);
        return *this;
    }

    ~String() {
        delete[] str;
    }

    int strlen(const char* s)
    {
        int i = 0;

        while (s[i] != '\0')
        {
            i++;
        }

        return i;
    }

    void strcpy(char* a, const char* b)
    {
        int i = 0;

        while (b[i] != '\0')
        {
            a[i] = b[i];
            i++;
        }

        a[i] = '\0';
    }



    void input()
    {
        cout << "vvedi stroky: \n";
        char buffer[256];

        cin.getline(buffer, 256);
        if (strlen(buffer) > size)
        {
            delete[] str;

            str = new char[strlen(buffer) + 1];
        }
        strcpy(str, buffer);


    }

    
    const char* get() const
    {
        return str;
    }
    


    
    void print() const
    {
        cout << str << endl;
    }


    static int getCount() {
        return count;
    }

};
int String::count = 0;