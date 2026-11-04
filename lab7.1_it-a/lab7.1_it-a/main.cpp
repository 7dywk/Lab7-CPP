#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Calc(int** a, const int rowCount, const int colCount, int& sum, int& k) {
    sum = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (!(a[i][j] % 2 != 0 && (i + j) % 7 == 0)) {
                sum += a[i][j];
                k++;
                a[i][j] = 0;
            }
        }
    }
}

#ifndef TEST
int main() {
    srand((unsigned)time(NULL));
    
    int Low = 9;
    int High = 61;
    int rowCount = 7;
    int colCount = 6;
    
    int** S = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        S[i] = new int[colCount];
    }

    Create(S, rowCount, colCount, Low, High);
    cout << "Original Matrix:" << endl;
    Print(S, rowCount, colCount);

    int sum = 0;
    int k = 0;
    Calc(S, rowCount, colCount, sum, k);
    
    cout << "Sum = " << sum << endl;
    cout << "Count = " << k << endl;
    
    cout << "Modified Matrix (with 0s):" << endl;
    Print(S, rowCount, colCount);

    for (int i = 0; i < rowCount; i++) {
        delete[] S[i];
    }
    delete[] S;
    
    return 0;
}
#endif
