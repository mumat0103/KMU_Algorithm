// 20180269 천성규

#include <iostream>
using namespace std;

int sudoku[5][5];
bool check_row[5][5];
bool check_col[5][5];
bool check_square[5][5];

int get_square(int row, int col)
{
    return (row / 2) * 2 + (col / 2);
}

void print()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << sudoku[i][j] << " ";
        cout << "\n";
    }
}

bool solve(int num)
{
    if (num == 16)
    {
        print();
        return true;
    }

    int x = num / 4;
    int y = num % 4;

    if (sudoku[x][y] != 0)
    {
        return solve(num + 1);
    }
    else
    {
        for (int i = 1; i <= 4; i++)
        {
            if (!check_row[x][i] && !check_col[y][i] && !check_square[get_square(x, y)][i])
            {
                check_row[x][i] = true;
                check_col[y][i] = true;
                check_square[get_square(x, y)][i] = true;
                sudoku[x][y] = i;

                if (solve(num + 1))
                {
                    return true;
                }
                check_row[x][i] = false;
                check_col[y][i] = false;
                check_square[get_square(x, y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i <= 4; i++)
            for (int j = 0; j <= 4; j++)
            {
                check_row[i][j] = false;
                check_col[i][j] = false;
                check_square[i][j] = false;
            }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> sudoku[i][j];

                if (sudoku[i][j] != 0)
                {
                    check_row[i][sudoku[i][j]] = true;
                    check_col[j][sudoku[i][j]] = true;
                    check_square[get_square(i, j)][sudoku[i][j]] = true;
                }
            }
        }

        solve(0);
    }
    return 0;
}