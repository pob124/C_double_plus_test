#include <iostream>
#include "GoodsManager.h"
#include "Goods.h"
#include "Book.h"
#include "DVD.h"
#include "TextBook.h"



GoodsManager::GoodsManager() {
	 nextId = 0;
	 numberOfGoods = 0;
	 for (int i = 0; i < 100; ++i) {
		 g[i] = new Goods(0, 0, "description", "maker",0);
	 }
}
GoodsManager::~GoodsManager() {

	for (int i = 0; i < 100; ++i) {
		delete g[i];
	}

}

void GoodsManager::operate() {

	int choice;
	int key;
	int goods_type;
	key = 1;
	while (key) {

		 std::cout << "다음 숫자중 아무거나 고르세요." <<  endl;
		 std::cout << "1 : 상품추가\n2 : 모든상품조회\n3 : 끝내기" <<  endl;
		 std::cout << "입력 : ";
		 cin >> choice;
		 if (cin.fail()) {
			 cin.clear();
			 cin.ignore(256, '\n');
			 continue;
		 }
		 std::cout <<  endl;

		switch (choice) {

		case 1:
			if (numberOfGoods >= 100) {
				 cerr << "상품을 추가 할 수 없습니다.(초과 오류)" <<  endl;
				key = 0;
			}
			else {
				 std::cout << "추가할 상품의 종류를 골라주세요." <<  endl;
				 std::cout << "1 : 책\n2 : 음반\n3 : 교재" <<  endl;
				 std::cout << "입력 : ";
				 cin >> goods_type;
				 std::cout <<  endl;
				addGoods(goods_type);
				numberOfGoods++;
			}
			break;

		case 2:

			for (int i = 0; i <= numberOfGoods; i++) {

				Goods* temp = (Goods*)g[i];
				int temp_num = temp->getType();
				switch (temp_num){
					case 1:
						{
						Book* temp_b = (Book*)temp;
						temp_b->showBook();
						break;
						}

					case 2:
						{
						DVD* temp_d = (DVD*)temp;
						temp_d->showDVD();
						break;
						}

					case 3:
						{
						TextBook* temp_t = (TextBook*)temp;
						temp_t->showTextBook();
						break;
						}
				}

			}
			break;
		case 3:
			 cout << "프로그램을 종료합니다." <<  endl;
			key = 0;
			break;

		default :
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
	}
}

void GoodsManager::addGoods(int type){

	switch (type) {
		case 1:
		{
				string desc;
				string maker;
				int price;
				int ISBN;
				string title;
				string author;
				cin.ignore();
				 std::cout << "책번호 : ";
				 getline(cin,desc);
				 std::cout <<  endl;
				 std::cout << "책제목 : ";
				 getline(cin,title);
				 std::cout <<  endl;
				 std::cout << "저자 : ";
				 getline(cin,author);
				 std::cout <<  endl;
				 std::cout << "출판사 : ";
				 getline(cin,maker);
				 std::cout <<  endl;
				 std::cout << "가격 : ";
				 cin >> price;
				 std::cout <<  endl;
				 std::cout << "책의 ISBN : ";
				 cin >> ISBN;
				 std::cout <<  endl;
				g[nextId] = new Book(type,nextId++,desc,maker,price,ISBN,title,author);
			break;
		}
	case 2:
		{
			string desc;
			string maker;
			string albumTitle;
			string artist;
			int price;
			cin.ignore();
			 std::cout << "DVD 번호 : ";
			 getline(cin,desc);
			 std::cout <<  endl;
			 std::cout << "음반 제목 : ";
			 getline(cin, albumTitle);
			 std::cout <<  endl;
			 std::cout << "가수 : ";
			 getline(cin, artist);
			 std::cout <<  endl;
			 std::cout << "음반사 : ";
			 getline(cin, maker);
			 std::cout <<  endl;
			 std::cout << "가격 : ";
			 cin >> price;
			 std::cout <<  endl;
			g[nextId] = new DVD(type, nextId++, desc, maker, price, albumTitle, artist);
			break;
		}
	case 3:
		{
			string desc;
			string maker;
			int price;
			int ISBN;
			string title;
			string author;
			string major;
			cin.ignore();
			 std::cout << "교재 번호 : ";
			 getline(cin,desc);
			 std::cout <<  endl;
			 std::cout << "교재 제목 : ";
			 getline(cin,title);
			 std::cout <<  endl;
			 std::cout << "저자 : ";
			 getline(cin,author);
			 std::cout <<  endl;
			 std::cout << "출판사 : ";
			 getline(cin,maker);
			 std::cout <<  endl;
			 std::cout << "가격 : ";
			 cin >> price;
			 std::cout <<  endl;
			 std::cout << "전공 : ";
			 cin >> major;
			 std::cout <<  endl;
			 std::cout << "책의 ISBN : ";
			 cin >> ISBN;
			 std::cout <<  endl;
			g[nextId] = new TextBook(type, nextId++, desc, maker, price, ISBN, title, author,major);
			break;
		}

	}

}

Goods::Goods(int type, int goodsID, string description, string maker, int price) {

	this->type = type;
	this->goodsID = goodsID;
	this->description = description;
	this->maker = maker;
	this->price = price;

}

void Goods::showGoods() {
	 std::cout << "--- 상품ID : " << goodsID + 1 <<  endl;
	 std::cout << "\t상품 명 : " << description <<  endl;
	 std::cout << "\t생산자 : " << maker <<  endl;
	 std::cout << "\t가격 : " << price <<  endl;
}

Book::Book(int type, int goodsID, string description, string maker, int price, int ISBN, string title, string author) : Goods(type, goodsID, description, maker, price) {
	this->ISBN = ISBN;
	this->title = title;
	this->author = author;
}

void Book::showBook(){
	this->showGoods();
	 std::cout << "\tISBN : " << ISBN <<  endl;
	 std::cout << "\t책제목 : " << title <<  endl;
	 std::cout << "\t저자 : " << author <<  endl;
}


DVD::DVD(int type, int goodsID, string description, string maker, int price, string albumTitle, string artist) : Goods(type, goodsID, description, maker, price){
	this->albumTitle = albumTitle;
	this->artist = artist;
}
void DVD::showDVD() {
	this->showGoods();
	std::cout << "\t앨범제목 : " << albumTitle <<  endl;
	 std::cout << "\t가수 : " << artist <<  endl;

}

TextBook::TextBook(int type, int goodsID, string description, string maker, int price, int ISBN, string title, string author, string major) : Book(type,goodsID,description,maker,price,ISBN,title,author){

	this->major = major;

}

void TextBook::showTextBook() {
	this->showBook();
	 std::cout << "\t전공 : " << major <<  endl;
}