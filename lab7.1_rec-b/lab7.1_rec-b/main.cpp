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

void ChangeRecursive(int** a, const int row1, const int row2, const int colCount, int j) {
    if (j == colCount) return;
    
    int tmp = a[row1][j];
    a[row1][j] = a[row2][j];
    a[row2][j] = tmp;
    
    ChangeRecursive(a, row1, row2, colCount, j + 1);
}

void SortRecursive(int** a, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 >= rowCount - 1) return;
    
    if (i1 < rowCount - i0 - 1) {
        if ((a[i1][0] > a[i1 + 1][0]) ||
            (a[i1][0] == a[i1 + 1][0] && a[i1][1] < a[i1 + 1][1]) ||
            (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2]))
        {
            ChangeRecursive(a, i1, i1 + 1, colCount, 0);
        }
        SortRecursive(a, rowCount, colCount, i0, i1 + 1);
    } else {
        SortRecursive(a, rowCount, colCount, i0 + 1, 0);
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

    SortRecursive(S, rowCount, colCount, 0, 0);
    cout << "Sorted Matrix (Recursive):" << endl;
    PrintRecursive(S, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++) {
        delete[] S[i];
    }
    delete[] S;
    
    return 0;
}
#endif

