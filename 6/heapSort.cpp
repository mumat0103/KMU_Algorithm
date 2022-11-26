// 20180269 천성규
#include <iostream>
using namespace std;

int arr[1100];
int n;
int count = 0;

void fixheap(int i, int len)
{
    int j = i * 2;
    int k = arr[i];
    while (j <= len)
    {
        if (j < len)
        {
            if (arr[j] < arr[j + 1])
                j++;
            count++;
        }

        count++;

        if (k > arr[j])
            break;

        arr[j / 2] = arr[j];
        j *= 2;
    }
    arr[j / 2] = k;
}

void swap(int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void heapSort()
{
    for (int heapsize = n; heapsize >= 2; heapsize--)
    {
        swap(1, heapsize);
        fixheap(1, heapsize - 1);
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        for (int i = n / 2; i >= 1; i--)
            fixheap(i, n);

        heapSort();

        cout << count << endl;
        count = 0;
    }

    return 0;
}