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

	sName = "복사생성" + obj.sName;
}

void Student::show() {

	cout << endl << "학생의 학번 : " << sID << ",\t이름 : " << sName << endl;


}