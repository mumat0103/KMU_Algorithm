//한국역사학과 20180269 천성규
#include <iostream>
using namespace std;

#define MAX_SIZE 100
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int FindingMax(int a[], int left, int right);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[MAX_SIZE];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << FindingMax(arr, 0, n) << "\n";
    }

    return 0;
}

int FindingMax(int a[], int left, int right)
{
    int half;

    if (left == right)
        return a[left];
    else
    {
        half = (left + right) / 2;
        int left_max = FindingMax(a, left, half);
        int right_max = FindingMax(a, half + 1, right);
        return MAX(left_max, right_max);
    }
}