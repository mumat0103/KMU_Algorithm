#include <iostream>
using namespace std;

#define MAX_SIZE 101

void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int low, int high);

int cnt = 0;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cnt = 0;
        int n, a[MAX_SIZE];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        mergeSort(a, 0, n - 1);

        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}

void merge(int a[], int low, int mid, int high)
{

    int i, j, k;
    int temp[MAX_SIZE];

    for (i = low; i <= high; i++)
        temp[i] = a[i];

    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        cnt++;
        if (temp[i] <= temp[j])
            a[k++] = temp[i++];
        else
            a[k++] = temp[j++];
    }
    while (i <= mid)
        a[k++] = temp[i++];

    while (j <= high)
        a[k++] = temp[j++];
}

void mergeSort(int v[], int low, int high)
{
    int mid;
    if (low == high)
        return;
    mid = (low + high) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}