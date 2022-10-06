#include <iostream>
using namespace std;

#define MAX 101

int maxSubSum(int a[], int n, int *start, int *end);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[MAX];
        int start, end;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << maxSubSum(a, n, &start, &end) << " " << start << " " << end << endl;
    }
    return 0;
}

int maxSubSum(int a[], int n, int *start, int *end)
{
    int i, j;
    int maxSum = 0, thisSum = 0;

    *start = *end = -1;

    for (i = 0, j = 0; j < n; j++)
    {
        thisSum += a[j];

        if (thisSum > maxSum)
        {
            maxSum = thisSum;

            if (a[i] == 0)
                i++;
            *start = i;
            *end = j;
        }
        else if (thisSum < 0)
        {
            i = j + 1;
            thisSum = 0;
        }
    }
    if (maxSum == 0)
        *start = *end = -1;
    return maxSum;
}