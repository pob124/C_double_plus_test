#include <iostream>
#include "copyCreate.h"
using namespace std;

void title() {

    cout << "********************************************************" << endl;
    cout << "  �� ���α׷��� ���� ���� ���� ���α׷��Դϴ�." << endl;
    cout <<    "  �й� : 2020810077, �̸� : ȫâ��" << endl;
    cout << "********************************************************" << endl;
}












int main() {
    title();

    Student s1(1234, "ȫâ��");	// �������� �̸����� ������ ��!
    Student s2(s1);

    Student s3(1236, "���Ǽ�");
    Student s4 = s3;

    s1.show();
    s2.show();
    s3.show();
    s4.show();

} // End of main() 