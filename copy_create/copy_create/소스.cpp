#include <iostream>
#include "copyCreate.h"
using namespace std;

void title() {

    cout << "********************************************************" << endl;
    cout << "  이 프로그램은 복사 생성 예시 프로그램입니다." << endl;
    cout <<    "  학번 : 2020810077, 이름 : 홍창현" << endl;
    cout << "********************************************************" << endl;
}












int main() {
    title();

    Student s1(1234, "홍창현");	// 제출자의 이름으로 수정할 것!
    Student s2(s1);

    Student s3(1236, "최판서");
    Student s4 = s3;

    s1.show();
    s2.show();
    s3.show();
    s4.show();

} // End of main() 