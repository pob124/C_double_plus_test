#include <iostream>
#include "complex.h"
#include <string>
using namespace std;

void title() {

    cout << "************************************************" << endl;
    cout << "  이 프로그램은 복소수 연산 프로그램입니다." << endl;
    cout <<    "  학번 : 2020810077, 이름 : 홍창현" << endl;
    cout << "************************************************" << endl;

};


int main()
{
    title();
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = add(c1, c2);

    cout << endl;
    cout << "*** 프렌드 선언 예제 ***" << endl;
    print("c1 = ", c1);
    print("c2 = ", c2);
    print("c3 = c1 + c2  = ", c3);

    cout << endl;
    cout << "*** 연산자(+) 중복 예제 ***" << endl;
    Complex c4 = c1 + c2;
    print("c4 = c1 + c2 = ", c4);
    cout << endl;
    cout << "*** 연산자(==) 중복 예제 ***" << endl;
    cout << "  if (c1 == c2) : " << (c1 == c2) << endl;
    cout << "  if (c3 == c4) : " << (c3 == c4) << endl;

    cout << endl;
    cout << "*** 연산자(++) 중복 예제 ***" << endl;
    print("c1 = ", c1);
    print("c2 = ", c2);

    Complex c5;
    c5 = c1++;
    cout << "(전위) c5 = c1++;" << endl;
    print("  c5 = ", c5);
    print("  c1 = ", c1);
    Complex c6;
    c6 = ++c2;
    cout << "(후위) c6 = ++c2;" << endl;
    print("  c6 = ", c6);
    print("  c2 = ", c2);

    return 0;
} // End of main()