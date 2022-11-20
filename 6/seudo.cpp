#include <iostream>
using namespace std;

#define N 4
int col[N];

void printNqueens()
{
    for (int i = 0; i < N; i++)
        cout << col[i] + 1 << " ";
    cout << endl;
}

int isPromising(int row)
{
    int k;
    int promising;
    k = 0;
    promising = 1;
    while (k < row && promising)
    {
        if (col[row] == col[k] || abs(col[row] - col[k]) == row - k)
            promising = 0;
        k++;
    }
    return promising;
}

void nQueens(int row)
{
    int i;
    if (isPromising(row))
        if (row == N - 1)
            printNqueens();
        else
            for (i = 0; i < N; i++)
            {
                col[row + 1] = i;
                nQueens(row + 1);
            }
}

int main()
{
    int i;

    for (i = 0; i < N; i++)
    {
        col[0] = i;
        nQueens(0);
    }
    return 0;
}