#define TEST
#include <iostream>
#include <cassert>
#include "../../lab7.1_it/lab7.1_it/main.cpp"

using namespace std;

int main() {
    int rowCount = 4;
    int colCount = 3;
    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    // Рядок 0: сума індексів 0 (кратно 7). 5 - непарне (викидаємо).
    // Рядок 1: 8, 9, 2
    // Рядок 2: 10, 5, 4
    // Рядок 3: 10, 7, 3
    a[0][0] = 5;  a[0][1] = 5; a[0][2] = 1;
    a[1][0] = 8;  a[1][1] = 9; a[1][2] = 2;
    a[2][0] = 10; a[2][1] = 5; a[2][2] = 4;
    a[3][0] = 10; a[3][1] = 7; a[3][2] = 3;

    // 1. Тест сортування
    Sort(a, rowCount, colCount);
    // Очікуваний порядок після сортування (↑ ↓ ↓):
    assert(a[0][0] == 5  && a[0][1] == 5 && a[0][2] == 1);
    assert(a[1][0] == 8  && a[1][1] == 9 && a[1][2] == 2);
    assert(a[2][0] == 10 && a[2][1] == 7 && a[2][2] == 3);
    assert(a[3][0] == 10 && a[3][1] == 5 && a[3][2] == 4);

    // 2. Тест обчислень
    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);
    
    // Перевіряємо кількість і суму (a[0][0]=5 відсіюється через непарність і (0+0)%7==0)
    // Всі інші елементи додаються: 5+1 + 8+9+2 + 10+7+3 + 10+5+4 = 64
    assert(k == 11);
    assert(S == 64);
    assert(a[0][0] == 5);
    assert(a[0][1] == 0); 

    for (int i = 0; i < rowCount; i++) delete[] a[i];
    delete[] a;

    cout << "All tests passed!" << endl;
    return 0;
}
