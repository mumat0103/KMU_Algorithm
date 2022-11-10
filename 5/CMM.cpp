// 20180269 천성규
#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

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
    int min_ = 987654321;
    int count;

    for (k = i; k < j; k++)
    {
        count = cmm(a, i, k) + cmm(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        min_ = min(count, min_);
    }

    return min_;
}