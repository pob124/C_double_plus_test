#pragma once
#include <string>
using namespace std;

class Goods {
	int type; // Book : 1, DVD : 2, TextBook : 3
		int goodsID;
	string description;
	string maker;
	int price;
public:
	Goods(int type, int goodsID, string description, string maker, int price);
	void showGoods();
	int getGoodsID() { return goodsID; }
	string getDescription() { return description; }
	string getMaker() { return maker; }
	int getPrice() { return price; }
	int getType() { return type; }
};
