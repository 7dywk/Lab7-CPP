#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateRecursive(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i == rowCount) return;
    if (j < colCount) {
        a[i][j] = Low + rand() % (High - Low + 1);
        CreateRecursive(a, rowCount, colCount, Low, High, i, j + 1);
    } else {
        CreateRecursive(a, rowCount, colCount, Low, High, i + 1, 0);
    }
}

void PrintRecursive(int** a, const int rowCount, const int colCount, int i, int j) {
    if (i == rowCount) return;
    if (j < colCount) {
        cout << setw(4) << a[i][j];
        PrintRecursive(a, rowCount, colCount, i, j + 1);
    } else {
        cout << endl;
        PrintRecursive(a, rowCount, colCount, i + 1, 0);
    }
}

void CalcRecursive(int** a, const int rowCount, const int colCount, int& sum, int& k, int i, int j) {
    if (i == rowCount) return;
    if (j < colCount) {
        if (!(a[i][j] % 2 != 0 && (i + j) % 7 == 0)) {
            sum += a[i][j];
            k++;
            a[i][j] = 0;
        }
        CalcRecursive(a, rowCount, colCount, sum, k, i, j + 1);
    } else {
        CalcRecursive(a, rowCount, colCount, sum, k, i + 1, 0);
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

    CreateRecursive(S, rowCount, colCount, Low, High, 0, 0);
    cout << "Original Matrix (Recursive):" << endl;
    PrintRecursive(S, rowCount, colCount, 0, 0);
    cout << endl;

    int sum = 0;
    int k = 0;
    CalcRecursive(S, rowCount, colCount, sum, k, 0, 0);
    
    cout << "Sum = " << sum << endl;
    cout << "Count = " << k << endl;
    
    cout << "Modified Matrix (with 0s):" << endl;
    PrintRecursive(S, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++) {
        delete[] S[i];
    }
    delete[] S;
    
    return 0;
}
#endif
