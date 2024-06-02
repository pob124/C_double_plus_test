#include <iostream>
#include "calling.h"
#include <string>
using namespace std;

void title()
{
    cout << "***********************************************************" << endl;
    cout << "  이 프로그램은 C++ 입출력에 대한 실습 프로그램입니다." << endl;
    cout << "  학번 : 2020810077,    이름 : 홍창현" << endl << endl;
}

ostream& operator << (ostream& outs, Contact contact) {

    outs << contact.name << " (" << contact.telNum << " , " << contact.address << ")";
    return outs;

}

istream& operator >> (istream& ins, Contact& contact) {

    cout << "연락처 정보를 입력하세요." << endl;
    cout << "이름\t: ";
    ins >> contact.name;
    cout <<"전화번호\t: ";
    ins >> contact.telNum;
    cout <<"주소\t: ";
    //ins >> ws;  
    getline(ins, contact.address);
    return ins;

}