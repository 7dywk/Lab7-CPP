#define TEST
#include <iostream>
#include <cassert>
#include "../../lab7.1_it-a/lab7.1_it-a/main.cpp"

using namespace std;

int main() {
    int rowCount = 2;
    int colCount = 2;
    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }


    a[0][0] = 5;
    a[0][1] = 10;
    a[1][0] = 7;
    a[1][1] = 4;

    int sum = 0, k = 0;
    Calc(a, rowCount, colCount, sum, k);

    assert(k == 3);
    assert(sum == 21);

    assert(a[0][0] == 5);
    assert(a[0][1] == 0);
    assert(a[1][0] == 0);
    assert(a[1][1] == 0);

    for (int i = 0; i < rowCount; i++) delete[] a[i];
    delete[] a;

    cout << "7.1-a Iterative: All tests passed!" << endl;
    return 0;
}
