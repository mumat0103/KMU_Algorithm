#include <iostream>
using namespace std;

int F[2][2] = {{1, 1}, {1, 0}};
void multy(int F[2][2], int M[2][2])
{
    int w = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int x = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int y = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int z = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = w % 1000;
    F[0][1] = x % 1000;
    F[1][0] = y % 1000;
    F[1][1] = z % 1000;
}

void power(int n)
{
    if (n <= 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};
    power(n / 2);

    multy(F, F);
    if (n % 2 == 1)
        multy(F, M);
}

int fibo(int n)
{
    if (n == 0)
        return 0;
    power(n - 1);
    return F[0][0];
}

int main(void)
{
    int x;
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        F[0][0] = 1;
        F[0][1] = 1;
        F[1][0] = 1;
        F[1][1] = 0;
        int tmp;
        cin >> tmp;
        cout << fibo(tmp) << "\n";
    }
}