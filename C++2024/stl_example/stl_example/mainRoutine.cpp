#include <iostream>
#include "word.h"
using namespace std;
void title()
{
    cout << "************************************************" << endl;
    cout << " �� ���α׷��� ���ѻ���(STL �ǽ�) ���α׷��Դϴ�." << endl;
    cout << " �й� : 2020810077 �̸� : ȫâ��" << endl;
    cout << "************************************************" << endl;

    cout << " ���� �������� 9���� �ܾ ���ʿ� �ԷµǾ� �ֽ��ϴ�.";
}
int main() {
    title();
    WordQuiz quiz1;
    quiz1.run();
    return 0;
} // End of main()