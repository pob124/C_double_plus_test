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

		 std::cout << "���� ������ �ƹ��ų� ������." <<  endl;
		 std::cout << "1 : ��ǰ�߰�\n2 : ����ǰ��ȸ\n3 : ������" <<  endl;
		 std::cout << "�Է� : ";
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
				 cerr << "��ǰ�� �߰� �� �� �����ϴ�.(�ʰ� ����)" <<  endl;
				key = 0;
			}
			else {
				 std::cout << "�߰��� ��ǰ�� ������ ����ּ���." <<  endl;
				 std::cout << "1 : å\n2 : ����\n3 : ����" <<  endl;
				 std::cout << "�Է� : ";
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
			 cout << "���α׷��� �����մϴ�." <<  endl;
			key = 0;
			break;

		default :
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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
				 std::cout << "å��ȣ : ";
				 getline(cin,desc);
				 std::cout <<  endl;
				 std::cout << "å���� : ";
				 getline(cin,title);
				 std::cout <<  endl;
				 std::cout << "���� : ";
				 getline(cin,author);
				 std::cout <<  endl;
				 std::cout << "���ǻ� : ";
				 getline(cin,maker);
				 std::cout <<  endl;
				 std::cout << "���� : ";
				 cin >> price;
				 std::cout <<  endl;
				 std::cout << "å�� ISBN : ";
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
			 std::cout << "DVD ��ȣ : ";
			 getline(cin,desc);
			 std::cout <<  endl;
			 std::cout << "���� ���� : ";
			 getline(cin, albumTitle);
			 std::cout <<  endl;
			 std::cout << "���� : ";
			 getline(cin, artist);
			 std::cout <<  endl;
			 std::cout << "���ݻ� : ";
			 getline(cin, maker);
			 std::cout <<  endl;
			 std::cout << "���� : ";
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
			 std::cout << "���� ��ȣ : ";
			 getline(cin,desc);
			 std::cout <<  endl;
			 std::cout << "���� ���� : ";
			 getline(cin,title);
			 std::cout <<  endl;
			 std::cout << "���� : ";
			 getline(cin,author);
			 std::cout <<  endl;
			 std::cout << "���ǻ� : ";
			 getline(cin,maker);
			 std::cout <<  endl;
			 std::cout << "���� : ";
			 cin >> price;
			 std::cout <<  endl;
			 std::cout << "���� : ";
			 cin >> major;
			 std::cout <<  endl;
			 std::cout << "å�� ISBN : ";
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
	 std::cout << "--- ��ǰID : " << goodsID + 1 <<  endl;
	 std::cout << "\t��ǰ �� : " << description <<  endl;
	 std::cout << "\t������ : " << maker <<  endl;
	 std::cout << "\t���� : " << price <<  endl;
}

Book::Book(int type, int goodsID, string description, string maker, int price, int ISBN, string title, string author) : Goods(type, goodsID, description, maker, price) {
	this->ISBN = ISBN;
	this->title = title;
	this->author = author;
}

void Book::showBook(){
	this->showGoods();
	 std::cout << "\tISBN : " << ISBN <<  endl;
	 std::cout << "\tå���� : " << title <<  endl;
	 std::cout << "\t���� : " << author <<  endl;
}


DVD::DVD(int type, int goodsID, string description, string maker, int price, string albumTitle, string artist) : Goods(type, goodsID, description, maker, price){
	this->albumTitle = albumTitle;
	this->artist = artist;
}
void DVD::showDVD() {
	this->showGoods();
	std::cout << "\t�ٹ����� : " << albumTitle <<  endl;
	 std::cout << "\t���� : " << artist <<  endl;

}

TextBook::TextBook(int type, int goodsID, string description, string maker, int price, int ISBN, string title, string author, string major) : Book(type,goodsID,description,maker,price,ISBN,title,author){

	this->major = major;

}

void TextBook::showTextBook() {
	this->showBook();
	 std::cout << "\t���� : " << major <<  endl;
}