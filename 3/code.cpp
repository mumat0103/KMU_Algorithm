#include <iostream>
using namespace std;

#define MAXSIZE 110

int MaxSubarray3(int A[], int Left, int Right);

int MaxSubarray3(int A[], int Left, int Right)
{
    int MaxSum, MaxLeft, MaxRight, MaxCenter;
    int MaxCenterL, MaxCenterR, ThisSum;
    int Center, i;
    if (Left == Right)
    {
        if (A[Left] > 0)
            return A[Left];
        else
            return 0;
    }
    Center = (Left + Right) / 2;
    MaxLeft = MaxSubarray3(A, Left, Center);
    MaxRight = MaxSubarray3(A, Center + 1, Right);
    MaxCenterL = 0;
    ThisSum = 0;
    for (i = Center; i >= Left; i--)
    {
        ThisSum = ThisSum + A[i];
        MaxCenterL = max(MaxCenterL, ThisSum);
    }
    MaxCenterR = 0;
    ThisSum = 0;
    for (i = Center + 1; i <= Right; i++)
    {
        ThisSum = ThisSum + A[i];
        MaxCenterR = max(MaxCenterR, ThisSum);
    }
    MaxCenter = MaxCenterL + MaxCenterR;
    MaxSum = max(max(MaxLeft, MaxRight), MaxCenter);
    return MaxSum;
}

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
        cout << MaxSubarray3(a, 0, n - 1) << endl;
    }
    return 0;
}