#include <iostream>
#include "calling.h"

using namespace std;

int main() {
    Contact person1, person2, person3;

    title();

    cout << "세 사람의 연락처를 이름, 전화번호, 주소 순으로 입력하시요." << endl;
    cout << "세번째 연락처에는 수강생 본인의 연락처를 입력하시오." << endl;
    cout << "***********************************************************" << endl << endl;

    cin >> person1 >> person2 >> person3; 	 // 연락처(이름,전화번호,주소)를 키보드로부터 읽는다.

    cout << "세 사람의 연락처를 출력하면 다음과 같습니다." << endl << endl;
    cout << person1 << endl << person2 << endl << person3 << endl;
    // 연락처를 이름(전화번호,주소) 형식으를 출력한다.
    cout << "***********************************************************" << endl;
    return 0;
} // End of main()