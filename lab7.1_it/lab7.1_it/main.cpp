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

void Change(int** a, const int row1, const int row2, const int colCount) {
    int tmp;
    for (int j = 0; j < colCount; j++) {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}

void Sort(int** a, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < rowCount - 1; i0++) {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
            if ((a[i1][0] > a[i1 + 1][0]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2]))
            {
                Change(a, i1, i1 + 1, colCount);
            }
        }
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (!(a[i][j] % 2 != 0 && (i + j) % 7 == 0)) {
                S += a[i][j];
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

    Sort(S, rowCount, colCount);
    cout << "Sorted Matrix:" << endl;
    Print(S, rowCount, colCount);

    int sum = 0;
    int k = 0;
    Calc(S, rowCount, colCount, sum, k);
    
    cout << "S = " << sum << endl;
    cout << "k = " << k << endl;
    
    cout << "Modified Matrix (with 0s):" << endl;
    Print(S, rowCount, colCount);

    for (int i = 0; i < rowCount; i++) {
        delete[] S[i];
    }
    delete[] S;
    
    return 0;
}
#endif
