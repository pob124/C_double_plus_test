#include <iostream>
#include "complex.h"
#include <string>
using namespace std;

void title() {

    cout << "************************************************" << endl;
    cout << "  �� ���α׷��� ���Ҽ� ���� ���α׷��Դϴ�." << endl;
    cout <<    "  �й� : 2020810077, �̸� : ȫâ��" << endl;
    cout << "************************************************" << endl;

};


int main()
{
    title();
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = add(c1, c2);

    cout << endl;
    cout << "*** ������ ���� ���� ***" << endl;
    print("c1 = ", c1);
    print("c2 = ", c2);
    print("c3 = c1 + c2  = ", c3);

    cout << endl;
    cout << "*** ������(+) �ߺ� ���� ***" << endl;
    Complex c4 = c1 + c2;
    print("c4 = c1 + c2 = ", c4);
    cout << endl;
    cout << "*** ������(==) �ߺ� ���� ***" << endl;
    cout << "  if (c1 == c2) : " << (c1 == c2) << endl;
    cout << "  if (c3 == c4) : " << (c3 == c4) << endl;

    cout << endl;
    cout << "*** ������(++) �ߺ� ���� ***" << endl;
    print("c1 = ", c1);
    print("c2 = ", c2);

    Complex c5;
    c5 = c1++;
    cout << "(����) c5 = c1++;" << endl;
    print("  c5 = ", c5);
    print("  c1 = ", c1);
    Complex c6;
    c6 = ++c2;
    cout << "(����) c6 = ++c2;" << endl;
    print("  c6 = ", c6);
    print("  c2 = ", c2);

    return 0;
} // End of main()