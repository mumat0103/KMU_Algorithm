#include <iostream>
using namespace std;

#define MAX_SIZE 1100

void quickSortA(int v[], int low, int high);
void quickSortB(int v[], int low, int high);

int Hoare_partition(int a[], int low, int high);
int Lomuto_partition(int a[], int low, int high);

int HcompCnt = 0;
int HswapCnt = 0;
int LcompCnt = 0;
int LswapCnt = 0;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        HcompCnt, HswapCnt, LcompCnt, LswapCnt = 0;
        int n, a[MAX_SIZE], b[MAX_SIZE];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i];
        }
        quickSortA(a, 0, n - 1);
        quickSortB(b, 0, n - 1);
        printf("%d %d %d %d\n", HswapCnt, LswapCnt, HcompCnt, LcompCnt);
        HcompCnt = 0;
        HswapCnt = 0;
        LcompCnt = 0;
        LswapCnt = 0;
    }
    return 0;
}

void quickSortA(int v[], int low, int high)
{
    int pivotPos;
    if (high > low)
    {
        pivotPos = Hoare_partition(v, low, high);
        quickSortA(v, low, pivotPos);
        quickSortA(v, pivotPos + 1, high);
    }
}

void quickSortB(int v[], int low, int high)
{
    int pivotPos;
    if (high > low)
    {
        pivotPos = Lomuto_partition(v, low, high);
        quickSortB(v, low, pivotPos - 1);
        quickSortB(v, pivotPos + 1, high);
    }
}

int Hoare_partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
            HcompCnt++;
        } while (a[i] < pivot);

        do
        {
            j--;
            HcompCnt++;
        } while (a[j] > pivot);

        if (i < j)
        {
            swap(a[i], a[j]);
            HswapCnt++;
        }
        else
            return j;
    }
}

int Lomuto_partition(int a[], int low, int high)
{
    int i, j;
    int pivot, pivotPos, tmp;
    pivot = a[low];
    j = low;
    for (i = low + 1; i <= high; i++)
    {
        LcompCnt++;
        if (a[i] < pivot)
        {
            j++;
            LswapCnt++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    pivotPos = j;
    LswapCnt++;
    tmp = a[low];
    a[low] = a[pivotPos];
    a[pivotPos] = tmp;

    return pivotPos;
}