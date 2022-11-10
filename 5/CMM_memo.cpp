// 20180269 천성규
#include <iostream>
using namespace std;

int dp[110][110];

int cmm(int a[], int i, int j);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n + 1; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n + 1; i++)
            for (int j = 1; j < n + 1; j++)
                dp[i][j] = -1;
        int ret = cmm(a, 1, n);
        cout << ret << endl;
    }

    return 0;
}

int cmm(int a[], int i, int j)
{
    if (i == j)
        return 0;

    int k;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = 987654321;
    for (k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], cmm(a, i, k) + cmm(a, k + 1, j) + a[i - 1] * a[k] * a[j]);
    }

    return dp[i][j];
}