// 20180269 천성규
#include <iostream>
using namespace std;
#define MAX_LENGTH 110
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs(char a[], char b[], int m, int n);
int strlen(char a[]);

int dp[MAX_LENGTH][MAX_LENGTH];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char a[MAX_LENGTH];
        char b[MAX_LENGTH];

        cin >> a >> b;
        int len_a = strlen(a);
        int len_b = strlen(b);

        for (int i = 0; i <= len_a; i++)
            for (int j = 0; j <= len_b; j++)
                dp[i][j] = -1;

        int ret = lcs(a, b, strlen(a), strlen(b));

        cout << ret << endl;
    }

    return 0;
}

int lcs(char a[], char b[], int m, int n)
{

    if (m == 0 || n == 0)
        return 0;

    if (dp[m - 1][n - 1] != -1)
        return dp[m - 1][n - 1];

    if (a[m - 1] == b[n - 1])
    {
        dp[m - 1][n - 1] = 1 + lcs(a, b, m - 1, n - 1);
        return dp[m - 1][n - 1];
    }
    else
    {
        int ret1 = lcs(a, b, m - 1, n);
        int ret2 = lcs(a, b, m, n - 1);
        dp[m - 1][n - 1] = MAX(ret1, ret2);
        return dp[m - 1][n - 1];
    }
}

int strlen(char a[])
{
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        len = i + 1;

    return len;
}