// 20180269 천성규
#include <iostream>
using namespace std;
#define MAX_LENGTH 110
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs(char a[], char b[], int m, int n);
void printLCS(char a[], char b[], int m, int n);

int strlen(char a[]);

int dp[MAX_LENGTH][MAX_LENGTH];
int S[MAX_LENGTH][MAX_LENGTH];

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

        cout << ret << " ";
        printLCS(a, b, len_a, len_b);
        cout << endl;
    }

    return 0;
}

int lcs(char a[], char b[], int m, int n)
{
    int i, j;
    for (i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (i = 0; i <= n; i++)
        dp[0][i] = 0;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                S[i][j] = 0;
            }
            else
            {
                dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j]);
                if (dp[i][j] == dp[i][j - 1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
    return dp[m][n];
}

void printLCS(char a[], char b[], int m, int n)
{
    if (m == 0 || n == 0)
        return;
    if (S[m][n] == 0)
    {
        printLCS(a, b, m - 1, n - 1);
        printf("%c", a[m - 1]);
    }
    else if (S[m][n] == 1)
        printLCS(a, b, m, n - 1);
    else if (S[m][n] == 2)
        printLCS(a, b, m - 1, n);
}

int strlen(char a[])
{
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        len = i + 1;

    return len;
}