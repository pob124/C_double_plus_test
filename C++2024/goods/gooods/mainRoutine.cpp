#include <iostream>
#include "GoodsManager.h"
#include "Goods.h"
#include "Book.h"
#include "DVD.h"
#include "TextBook.h"

using namespace std;

void title() {

	cout << "****************************************************" << endl;
	cout << "  �� ���α׷��� ����� �̿��� ��ǰ ���� ���α׷��Դϴ�." << endl;
	cout <<	"  �й� : 2020810077 , �̸� : ȫâ��" << endl;
	cout << "****************************************************" << endl;

}

int main()
{
	title();

	GoodsManager man;
	man.operate();
} // End of main()