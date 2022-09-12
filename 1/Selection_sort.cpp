#include <iostream>
using namespace std;

void selectionSort(int a[], int n);
int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[1000];
        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> a[j];
        selectionSort(a, num);

        cout << "\n";
    }
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Selection Sort 함수 */
void selectionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    // selection sort 알고리즘 구현

    for (int i = 0; i < n - 1; i++)
    {
        int jMin = i;
        for (int j = i + 1; j < n; j++)
        {
            countCmpOps++;
            if (a[j] < a[jMin])
            {
                jMin = j;
            }
        }
        if (jMin != i)
        {
            countSwaps++;
            swap(a[jMin], a[i]);
        }
    }

    printf("%d %d ", countCmpOps, countSwaps);
}
