#include <iostream>
#include "calling.h"

using namespace std;

int main() {
    Contact person1, person2, person3;

    title();

    cout << "�� ����� ����ó�� �̸�, ��ȭ��ȣ, �ּ� ������ �Է��Ͻÿ�." << endl;
    cout << "����° ����ó���� ������ ������ ����ó�� �Է��Ͻÿ�." << endl;
    cout << "***********************************************************" << endl << endl;

    cin >> person1 >> person2 >> person3; 	 // ����ó(�̸�,��ȭ��ȣ,�ּ�)�� Ű����κ��� �д´�.

    cout << "�� ����� ����ó�� ����ϸ� ������ �����ϴ�." << endl << endl;
    cout << person1 << endl << person2 << endl << person3 << endl;
    // ����ó�� �̸�(��ȭ��ȣ,�ּ�) �������� ����Ѵ�.
    cout << "***********************************************************" << endl;
    return 0;
} // End of main()