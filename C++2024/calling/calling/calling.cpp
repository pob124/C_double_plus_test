#include <iostream>
#include "calling.h"
#include <string>
using namespace std;

void title()
{
    cout << "***********************************************************" << endl;
    cout << "  �� ���α׷��� C++ ����¿� ���� �ǽ� ���α׷��Դϴ�." << endl;
    cout << "  �й� : 2020810077,    �̸� : ȫâ��" << endl << endl;
}

ostream& operator << (ostream& outs, Contact contact) {

    outs << contact.name << " (" << contact.telNum << " , " << contact.address << ")";
    return outs;

}

istream& operator >> (istream& ins, Contact& contact) {

    cout << "����ó ������ �Է��ϼ���." << endl;
    cout << "�̸�\t: ";
    ins >> contact.name;
    cout <<"��ȭ��ȣ\t: ";
    ins >> contact.telNum;
    cout <<"�ּ�\t: ";
    //ins >> ws;  
    getline(ins, contact.address);
    return ins;

}