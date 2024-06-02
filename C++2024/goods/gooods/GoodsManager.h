#pragma once
#include "Goods.h"
class GoodsManager {
	int nextId;
	int numberOfGoods;
	Goods* g[100];
public:
	GoodsManager();
	~GoodsManager();
	void operate();
	void addGoods(int type);
};

