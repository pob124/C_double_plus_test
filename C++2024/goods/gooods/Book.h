#pragma once
#include <string>
using namespace std;

#include "Goods.h"

class Book : public Goods {
	int ISBN;
	string title;
	string author;
public:
	Book(int type, int goodsID, string description, string maker, int price, int ISBN, string title, string author);
	void showBook();

	void setTitle(string title) { this->title = title; }
	string getAuthor() { return author; }
	int getISBN() { return ISBN; }
};

