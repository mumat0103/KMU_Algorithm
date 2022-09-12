#include <iostream>
using namespace std;

void shellSort(int a[], int n);
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
        shellSort(a, num);

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
void shellSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수

    int shrinkRatio = 2;
    int gap = n / shrinkRatio;

    // selection sort 알고리즘 구현
    int i, j, tmp;
    while (gap > 0)
    {
        for (i = gap; i < n; i++)
        {
            tmp = a[i];
            for (j = i; j >= gap; j -= gap)
            {
                countCmpOps++;
                if (a[j - gap] > tmp)
                {
                    countSwaps++;
                    a[j] = a[j - gap];
                }
                else
                {
                    break;
                }
            }
            a[j] = tmp;
        }
        gap /= shrinkRatio;
    }

    printf("%d %d ", countCmpOps, countSwaps);
}
