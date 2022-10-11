#include <iostream>
using namespace std;

#define MAXSIZE 110
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubSum(int a[], int low, int high);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[MAXSIZE];
        int start, end;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << maxSubSum(a, 0, n - 1) << endl;
    }
    return 0;
}

int maxSubSum(int a[], int low, int high)
{
    if (high == low)
        return a[low];

    int mid = (low + high) / 2;
    int left_sum = maxSubSum(a, low, mid);
    int right_sum = maxSubSum(a, mid + 1, high);
    int cross_sumL = 0;
    int cross_sumR = 0;
    int this_sum = 0;

    for (int i = mid; i >= low; i--)
    {
        this_sum = this_sum + a[i];
        cross_sumL = MAX(cross_sumL, this_sum);
    }

    this_sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        this_sum = this_sum + a[i];
        cross_sumR = MAX(cross_sumR, this_sum);
    }

    int cross_sum = cross_sumL + cross_sumR;

    int first = MAX(left_sum, right_sum);
    int result = MAX(cross_sum, first);

    if (result <= 0)
        return 0;
    return result;
}