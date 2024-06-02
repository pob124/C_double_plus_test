#ifndef WORD
#define WORD
#include <iostream>
#include <vector>
using namespace std;

class Word {
private:
	string hanWord;		// �ѱ� �ܾ� 
	string engWord;			// ���� �ܾ� 
public:
	Word(string hanWord, string engWord) {
		this->hanWord = hanWord;
		this->engWord = engWord;
	}
	void show() {
		cout << " (" << hanWord << ',' << engWord << ')';
	}
	string print() {
		return " (" + hanWord + "," + engWord + ") ";
	}

	bool operator==(const Word& other) const {
		return (*this == other);
	}
	bool operator!=(const Word& other) const {
		return !(*this == other);
	}
	string getEngWord() { return engWord; }
	string getHanWord() { return hanWord; }
	string engWordReturn() {
		return(engWord);
	}
};

class WordQuiz {
    vector<Word> v;
    void addWord();
    void delWord();
    void listDic();
    void quiz();
    bool exist(string hanWord);
public:
    WordQuiz();
    void run();
};

#endif