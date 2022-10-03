#include <iostream>
using namespace std;

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

struct Point
{
    int x, y;
} point;

int knightTour(int m, int n, Point pos, int counter);
void printTour(int m, int n);

Point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int main()
{
    int tc;
    cin >> tc;

    int m, n, s, t, i, j;
    Point start;
    // m = 행, n = 열, (s, t) = 기사 좌표
    while (tc--)
    {
        cin >> m >> n >> s >> t;
        start.x = t;
        start.y = s;

        for (i = 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                board[i][j] = UNMARK;

        board[start.y][start.x] = MARK;
        path[start.y][start.x] = 1;

        if (knightTour(m, n, start, 1))
        {
            cout << 1 << "\n";
            printTour(m, n);
        }
        else
            cout << 0 << "\n";
    }
    return 0;
}

int knightTour(int m, int n, Point pos, int counter)
{
    int i;
    Point next;

    if (counter == m * n)
        return 1;

    for (i = 0; i < 8; i++)
    {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m && board[next.y][next.x] != MARK)
        {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter + 1;

            if (knightTour(m, n, next, counter + 1))
                return 1;

            board[next.y][next.x] = UNMARK;
        }
    }

    return 0;
}

void printTour(int m, int n)
{
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            cout << path[i][j] << " ";
        cout << "\n";
    }
}