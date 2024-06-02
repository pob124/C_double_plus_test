#ifndef CALLING
#define CALLING
#include <iostream>

using namespace std;

class Contact {
    string name;
    string telNum;
    string address;
public:
    Contact(string name = "", string telnum = "", string address = "") {
        this->name = name;
        this->telNum = telnum;
        this->address = address;
    }
    friend ostream& operator << (ostream& outs, Contact contact);
    // << 연산자를 프렌드로 선언
    friend istream& operator >> (istream& ins, Contact& contact);
    // >> 연산자를 프렌드로 선언
};

void title();

#endif