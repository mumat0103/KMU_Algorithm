//한국역사학과 20180269 천성규
#include <iostream>
using namespace std;

#define MAX_SIZE 100

int binarySearch(int a[], int left, int right, int value);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[MAX_SIZE];
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << binarySearch(arr, 0, n, k) << "\n";
    }

    return 0;
}

int binarySearch(int a[], int left, int right, int value)
{
    int mid;

    if (left > right)
        return -1;
    else
    {
        mid = (left + right) / 2;

        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            return binarySearch(a, left, mid - 1, value);
        else
            return binarySearch(a, mid + 1, right, value);
    }
}