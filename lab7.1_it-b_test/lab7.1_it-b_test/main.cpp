#define TEST
#include <iostream>
#include <cassert>
#include "../../lab7.1_it-b/lab7.1_it-b/main.cpp"// Зміни на свій шлях

using namespace std;

int main() {
    int rowCount = 4;
    int colCount = 3;
    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    a[0][0] = 10; a[0][1] = 5; a[0][2] = 1;
    a[1][0] = 8;  a[1][1] = 9; a[1][2] = 2;
    a[2][0] = 10; a[2][1] = 5; a[2][2] = 4;
    a[3][0] = 10; a[3][1] = 7; a[3][2] = 3;

    Sort(a, rowCount, colCount);

    assert(a[0][0] == 8  && a[0][1] == 9 && a[0][2] == 2);
    assert(a[1][0] == 10 && a[1][1] == 7 && a[1][2] == 3);
    assert(a[2][0] == 10 && a[2][1] == 5 && a[2][2] == 4);
    assert(a[3][0] == 10 && a[3][1] == 5 && a[3][2] == 1);

    for (int i = 0; i < rowCount; i++) delete[] a[i];
    delete[] a;

    cout << "7.1-b Iterative: All tests passed!" << endl;
    return 0;
}
