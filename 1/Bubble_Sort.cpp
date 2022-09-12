#include <iostream>
using namespace std;

void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main()
{
    int t;
    int a[1000], b[1000];

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
            cin >> b[j];

        copyArray(a, b, n);
        bubbleSort(a, n);

        copyArray(a, b, n);
        bubbleSortImproved1(a, n);

        copyArray(a, b, n);
        bubbleSortImproved2(a, n);

        cout << endl;
    }
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    for (int pass = 1; pass < n; pass++)
    {
        for (int i = 1; i <= n - pass; i++)
        {
            countCmpOps++;
            if (a[i - 1] > a[i])
            {
                countSwaps++;
                swap(a[i - 1], a[i]);
            }
        }
    }

    printf("%d %d ", countCmpOps, countSwaps);
}

void bubbleSortImproved1(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;

    for (int pass = 1; pass < n; pass++)
    {
        bool swapped = false;
        for (int i = 1; i <= n - pass; i++)
        {
            countCmpOps++;
            if (a[i - 1] > a[i])
            {
                countSwaps++;
                swap(a[i - 1], a[i]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    printf("%d %d ", countCmpOps, countSwaps);
}

void bubbleSortImproved2(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0;
    int lastSwappedPos = n;

    while (lastSwappedPos > 0)
    {
        int swappedPos = 0;
        for (int i = 1; i < lastSwappedPos; i++)
        {
            countCmpOps++;
            if (a[i - 1] > a[i])
            {
                countSwaps++;
                swap(a[i - 1], a[i]);
                swappedPos = i;
            }
        }
        lastSwappedPos = swappedPos;
    }

    printf("%d %d ", countCmpOps, countSwaps);
}

void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}
