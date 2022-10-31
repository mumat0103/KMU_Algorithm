#include <iostream>
using namespace std;

int findPeakValue(int a[], int start, int end);

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 9, 8, 7, 0};
    int l = sizeof(a) / sizeof(int);
    int peak = findPeakValue(a, 0, l);

    cout << peak << endl;
}

int findPeakValue(int a[], int start, int end)
{
    int mid;

    mid = start + (end - start) / 2;
    if ((mid == 0 || a[mid] >= a[mid - 1]) && (mid == end || a[mid + 1] <= a[mid]))
        return a[mid];
    else if (mid > 0 && a[mid] < a[mid - 1])
        return findPeakValue(a, start, mid - 1);
    else
        return findPeakValue(a, mid + 1, end);
}