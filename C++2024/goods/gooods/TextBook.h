#pragma once
#include <string>
using namespace std;

#include "Goods.h"
#include "Book.h"

class TextBook : public Book {
	string major;
public:
	TextBook(int type, int goodsID, string description, string maker, int price, int ISBN, string title, string author, string major);
	void showTextBook();

	string getMajor() { return major; }
}; 
