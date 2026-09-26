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

    void print() {
        cout << str << endl;
    }

    static int getCount() {
        return count;
    }


    String operator*(int count) const {
        if (count <= 0) return String(""); 
        int newSize = size * count;
        char* temp = new char[newSize + 1];
        temp[0] = '\0';

        for (int i = 0; i < count; i++) {
            strcat(temp, str); 
        }

        String result(temp);
        delete[] temp;
        return result;
    }

    String& operator++() {
        for (int i = 0; i < size; i++) {
            str[i] = toupper(str[i]); 
        }
        return *this;
    }

    bool operator!() const {
        return size == 0 || str[0] == '\0';
    }

    char& operator[](int index) {
        return str[index]; 
    }




    friend ostream& operator<<(ostream& out, const String& obj);
    friend istream& operator>>(istream& in, String& obj);


};

ostream& operator<<(ostream& out, const String& obj) {
    if (obj.str != nullptr) {
        out << obj.str;
    }
    return out;
}

istream& operator>>(istream& in, String& obj) {
    char buffer[256];
    in.getline(buffer, 256); 

    delete[] obj.str;
    obj.size = strlen(buffer);
    obj.str = new char[obj.size + 1];
    strcpy(obj.str, buffer);

    return in;
}

int String::count = 0;