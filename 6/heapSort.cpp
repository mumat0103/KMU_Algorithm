// 20180269 천성규
#include <iostream>
using namespace std;

int arr[1100];
int n;
int count = 0;

void fixheap(int i, int len)
{
    int c = i * 2;  // child
    int p = arr[i]; // parent
    while (c <= len)
    {
        if (c < len)
        {
            if (arr[c] < arr[c + 1])
                c++;
            count++;
        }
        count++;

        if (p > arr[c])
            break;

        swap(arr[c / 2], arr[c]);
        c *= 2;
    }
    arr[c / 2] = p;
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