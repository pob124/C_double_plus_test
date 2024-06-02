#include <iostream>
#include <string>
#include <sstream>
#include "word.h"
using namespace std;


WordQuiz::WordQuiz() {
    Word n[] = { Word("�ϳ�", "one"), Word("��", "two"), Word("��", "three"),
        Word("��", "four"), Word("�ټ�", "five"), Word("����", "six"),
        Word("�ϰ�", "seven"), Word("����", "eight"), Word("��ȩ", "nine") };
    for (int i = 0; i < 9; i++)
        v.push_back(n[i]);
}

void WordQuiz::run() {
    int choice;

    cout << endl;
    while (true) {
        cout << endl;
        cout << "�ϰ� ���� �۾��� ��ȣ�� �Է��Ͻÿ� !" << endl;
        cout << "( 1:�ܾ���ȸ, 2:�ܾ��߰�, 3:�ܾ����, 4:����Ǯ��, 5:���α׷� ���� ) >> ";
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
    cout << "(���� " << v.size() << "���� �ܾ �ֽ��ϴ�.)" << endl << endl;
    cout << "�߰��� �ܾ �ѱ۰� ����� ������� �Է��ϼ���." <<endl;
    cout << "\t'�ܾ��߰�'�� ��������, '- -'(��, ������ ��ĭ��� ������)�� �Է��ϼ���." << endl;

    while (true) {
        string han;
        string eng;
        cout << v.size() + 1 << "��° �ܾ�(�ѱ۰� ����� ������� �Է� >>";
        getline(cin, input);
        cout << endl;
        if (input == "- -") {
            cout << "�ܾ� �߰��� �����մϴ�." << endl;
            return;
        }
        istringstream iss(input);
        getline(iss, han, ' ');
        if (exist(han)) {
            cout << "�ܾ �̹� �����մϴ�." << endl;
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
        cout << "������ ���� �ܾ �Է��ϼ���. ('�ܾ����'�� ��������, 'exit' �� �Է�) >>";
        getline(cin, wantDel);
        cout << endl;
        if (wantDel == "exit") {
            cout << "����" << endl;
            return;
        }
        for (auto iter = v.begin(); iter != v.end(); iter++) {

            if ((*iter).getEngWord() == wantDel) {
                cout << "�ܾ�";
                (*iter).show();
                v.erase(iter);
                flag = true;
                break;
            }

        }
        if (!flag) {
            cout << "�ܾ� ���� ����" << endl;
        }
        else {
            cout << "�� (�Ǵ� �� ������)" << endl;
        }
    }
}
void WordQuiz::listDic() {

    cout << "����" << v.size() << "���� �ܾ �ֽ��ϴ�." << endl;
 
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
        cout << "�ܾ� " << answer->getHanWord() << " �� �ش��ϴ� ���� �ܾ �Է��ϼ���!(quiz ���Ḧ ���ϸ� 'exit' �Է�.)";
        getline(cin, input);
        cout << endl;
        if (input == "exit") {
            return;
        }
        if (input == answer->getEngWord()) {
            cout << "����!!!" << endl;
        }
        else {
            cout << "Ʋ�Ƚ��ϴ�!!!!" << endl;
        }
    }
}
