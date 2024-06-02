#pragma once
#include <string>
using namespace std;

#include "Goods.h"

class DVD : public Goods {
	string albumTitle;
	string artist;
public:
	DVD(int type, int goodsID, string description, string maker, int price, string albumTitle, string artist);
	void showDVD();

	string getAlbumTitle() { return albumTitle; }
	string getArtist() { return artist; }
};

