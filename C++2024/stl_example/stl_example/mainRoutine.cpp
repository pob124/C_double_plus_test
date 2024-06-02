#include <iostream>
#include "word.h"
using namespace std;
void title()
{
    cout << "************************************************" << endl;
    cout << " 이 프로그램은 영한사전(STL 실습) 프로그램입니다." << endl;
    cout << " 학번 : 2020810077 이름 : 홍창현" << endl;
    cout << "************************************************" << endl;

    cout << " 영한 사전에는 9개의 단어가 최초에 입력되어 있습니다.";
}
int main() {
    title();
    WordQuiz quiz1;
    quiz1.run();
    return 0;
} // End of main()