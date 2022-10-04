#include <iostream>
using namespace std;

void multiple(long long a[][2], long long b[][2]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[2][2] = {{1, 1}, {1, 0}};
        long long ans[2][2] = {{1, 0}, {0, 1}};
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                multiple(ans, a);
            }
            n /= 2;
            multiple(a, a);
        }
        cout << ans[1][0] << "\n";
    }
    return 0;
}

void multiple(long long a[][2], long long b[][2])
{
    long long temp[2][2];
    int sum;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            sum = 0;
            for (int k = 0; k < 2; k++)
            {
                sum += (a[i][k] * b[k][j]);
            }
            temp[i][j] = sum % 1000;
        }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = temp[i][j];
}