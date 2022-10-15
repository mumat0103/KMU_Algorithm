#include <iostream>
using namespace std;

#define MAX_SIZE 110
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void merge(int a[], int low, int mid, int high);
void mergeSortIterative(int v[], int n);

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
        mergeSortIterative(a, n);

        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}

void mergeSortIterative(int v[], int n)
{
    int size = 1;
    while (size < n)
    {
        for (int i = 0; i < n; i += 2 * size)
        {
            int low = i;
            int mid = low + size - 1;
            int high = MIN(i + 2 * size - 1, n - 1);
            if (mid >= n - 1)
                break;
            merge(v, low, mid, high);
        }
        size *= 2;
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAX_SIZE];
    for (i = low; i <= high; i++)
        tmp[i] = a[i];
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        cnt++;
        if (tmp[i] <= tmp[j]) // <---- 핵심연산자(비교연산자)
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }

    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}