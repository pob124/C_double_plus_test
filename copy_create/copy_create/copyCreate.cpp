#include <iostream>
#include "copyCreate.h"
#include <string>

using namespace std;

Student::Student(int id,const char* name) {

	sID = id;

	sName = name;

}

Student::Student(const Student& obj) {

	sID = obj.sID + 1;

	sName = "�������" + obj.sName;
}

void Student::show() {

	cout << endl << "�л��� �й� : " << sID << ",\t�̸� : " << sName << endl;


}