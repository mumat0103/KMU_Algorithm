// 20180269 천성규
#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs(char a[], char b[], int m, int n);
int strlen(char a[]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char a[11];
        char b[11];

        cin >> a >> b;

        int ret = lcs(a, b, strlen(a), strlen(b));
        cout << ret << endl;
    }

    return 0;
}

int lcs(char a[], char b[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (a[m - 1] == b[n - 1])
    {
        return 1 + lcs(a, b, m - 1, n - 1);
    }
    else
    {
        int ret1 = lcs(a, b, m - 1, n);
        int ret2 = lcs(a, b, m, n - 1);

        return MAX(ret1, ret2);
    }
}

int strlen(char a[])
{
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        len = i + 1;

    return len;
}