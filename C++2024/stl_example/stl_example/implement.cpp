#include <iostream>
#include <string>
#include <sstream>
#include "word.h"
using namespace std;


WordQuiz::WordQuiz() {
    Word n[] = { Word("하나", "one"), Word("둘", "two"), Word("셋", "three"),
        Word("넷", "four"), Word("다섯", "five"), Word("여섯", "six"),
        Word("일곱", "seven"), Word("여덟", "eight"), Word("아홉", "nine") };
    for (int i = 0; i < 9; i++)
        v.push_back(n[i]);
}

void WordQuiz::run() {
    int choice;

    cout << endl;
    while (true) {
        cout << endl;
        cout << "하고 싶은 작업의 번호를 입력하시오 !" << endl;
        cout << "( 1:단어조회, 2:단어추가, 3:단어삭제, 4:퀴즈풀기, 5:프로그램 종료 ) >> ";
        cin >> choice;
        switch (choice) {
        case 1: listDic(); break;
        case 2: addWord(); break;
        case 3: delWord(); break;
        case 4: quiz(); break;
        case 5: return;
        }
    }
}

bool WordQuiz::exist(string hanWord) {
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        if (iter->getHanWord() == hanWord) {
            return true;
        }
    }
    return  false;
}

void WordQuiz::addWord(){
    cin.ignore();
    string input;
    cout << "(현재 " << v.size() << "개의 단어가 있습니다.)" << endl << endl;
    cout << "추가할 단어를 한글과 영어로 순서대로 입력하세요." <<endl;
    cout << "\t'단어추가'를 끝내려면, '- -'(즉, 하이픈 한칸띄고 하이픈)을 입력하세요." << endl;

    while (true) {
        string han;
        string eng;
        cout << v.size() + 1 << "번째 단어(한글과 영어로 순서대로 입력 >>";
        getline(cin, input);
        cout << endl;
        if (input == "- -") {
            cout << "단어 추가를 종료합니다." << endl;
            return;
        }
        istringstream iss(input);
        getline(iss, han, ' ');
        if (exist(han)) {
            cout << "단어가 이미 존재합니다." << endl;
            continue;
        }
        getline(iss, eng, ' ');
        v.push_back(Word(han,eng));
    }

}
void WordQuiz::delWord() {
    cin.ignore();
    string wantDel;
    while (true) {
        bool flag = false;
        cout << "삭제할 영어 단어를 입력하세요. ('단어삭제'를 끝내려면, 'exit' 을 입력) >>";
        getline(cin, wantDel);
        cout << endl;
        if (wantDel == "exit") {
            cout << "종료" << endl;
            return;
        }
        for (auto iter = v.begin(); iter != v.end(); iter++) {

            if ((*iter).getEngWord() == wantDel) {
                cout << "단어";
                (*iter).show();
                v.erase(iter);
                flag = true;
                break;
            }

        }
        if (!flag) {
            cout << "단어 삭제 실패" << endl;
        }
        else {
            cout << "이 (또는 가 삭제됨)" << endl;
        }
    }
}
void WordQuiz::listDic() {

    cout << "현재" << v.size() << "개의 단어가 있습니다." << endl;
 
   for (auto iter = v.begin(); iter != v.end(); iter++) {
        (*iter).show();
        cout << endl;
        }
}
void WordQuiz::quiz() {
    cin.ignore();
    while (true) {
        string input;
        Word* answer;
        int randInt;
        randInt = rand() % v.size();
        answer = &v[randInt];
        cout << "단어 " << answer->getHanWord() << " 에 해당하는 영어 단어를 입력하세요!(quiz 종료를 원하면 'exit' 입력.)";
        getline(cin, input);
        cout << endl;
        if (input == "exit") {
            return;
        }
        if (input == answer->getEngWord()) {
            cout << "정답!!!" << endl;
        }
        else {
            cout << "틀렸습니다!!!!" << endl;
        }
    }
}
