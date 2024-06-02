#include <iostream>
#include "GoodsManager.h"
#include "Goods.h"
#include "Book.h"
#include "DVD.h"
#include "TextBook.h"

using namespace std;

void title() {

	cout << "****************************************************" << endl;
	cout << "  이 프로그램은 상속을 이용한 상품 관리 프로그램입니다." << endl;
	cout <<	"  학번 : 2020810077 , 이름 : 홍창현" << endl;
	cout << "****************************************************" << endl;

}

int main()
{
	title();

	GoodsManager man;
	man.operate();
} // End of main()