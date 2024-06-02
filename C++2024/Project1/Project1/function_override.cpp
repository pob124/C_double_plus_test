#include <iostream>
#include <iostream>
using namespace std;

void title() {

    cout << "************************************************" << endl;
    cout << "  이 프로그램은 함수 중복 프로그램입니다." << endl;
    cout << "  학번 : 2020810077, 이름 : 홍창현" << endl;
    cout << "************************************************" << endl;

}

int small(int x, int y) {

    int minimum;

    minimum = min(x, y);

    if (minimum < 0) {
         
        minimum = 0;

    }

    return minimum;
};

int small(int x, int y, int z) {

    int minimum;

    minimum = min(x, y);

    if (minimum < z) minimum = z;

    return minimum;

};


int smallOne(int x, int y , int z = 0){

    int minimum;

    minimum = min(x, y);

    if (minimum < z) minimum = z;

    return minimum;

}

int main() {
    title();
    int x[12] = { 1, -2, 1, -2, -2, 2, 1, -2, 1, -2, -2, 2 };
    int y[12] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    int z[12];

    z[0] = small(x[0], y[0]);
    z[1] = small(x[1], y[1]);
    z[2] = small(x[2], y[2], -2);
    z[3] = small(x[3], y[3], 2);
    z[4] = small(x[4], y[4], -1);
    z[5] = small(x[5], y[5], -1);

    z[6] = smallOne(x[6], y[6]);
    z[7] = smallOne(x[7], y[7]);
    z[8] = smallOne(x[8], y[8], -2);
    z[9] = smallOne(x[9], y[9], 2);
    z[10] = smallOne(x[10], y[10], -1);
    z[11] = smallOne(x[11], y[11], -1);

    cout << "************** 결과 ***************" << endl;
    cout << " small(1, 10)   \t===> " << z[0] << endl;
    cout << " small(-2, 10)   \t===> " << z[1] << " (정해진 최소값 : 0)" << endl;
    cout << " small(1, 10, -2)   \t===> " << z[2] << endl;
    cout << " small(-2, 10, 2)   \t===> " << z[3] << endl;
    cout << " small(-2, 10, -1)   \t===> " << z[4] << endl;
    cout << " small(2, 10, -1)   \t===> " << z[5] << endl;
    cout << " smallOne(1, 10)   \t===> " << z[6] << endl;
    cout << " smallOne(-2, 10)   \t===> " << z[7] << " (정해진 최소값 : 0)" << endl;
    cout << " smallOne(1, 10, -2)   \t===> " << z[8] << endl;
    cout << " smallOne(-2, 10, 2)   \t===> " << z[9] << endl;
    cout << " smallOne(-2, 10, -1)  \t===> " << z[10] << endl;
    cout << " smallOne(2, 10, -1)  \t===> " << z[11] << endl;
} // End of main()