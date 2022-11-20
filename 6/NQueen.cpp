// 20180269 천성규
#include <iostream>
using namespace std;

int n;
int col[20];
int flag;
void printQueens()
{
    for (int i = 0; i < n; i++)
        cout << col[i] + 1 << " ";
    cout << endl;
}

int isPromising(int row)
{
    int k;
    k = 0;
    int promising;
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
    {
        if (row == n - 1)
        {
            flag = 1;
            printQueens();
        }
        else
            for (i = 0; i < n; i++)
            {
                col[row + 1] = i;
                if (flag != 1)
                    nQueens(row + 1);
            }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        flag = 0;
        int i;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            col[0] = i;
            nQueens(0);
        }
    }

    return 0;
}