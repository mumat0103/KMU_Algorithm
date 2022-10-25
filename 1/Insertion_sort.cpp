#include <iostream>
using namespace std;

void insertionSort(int a[], int n);
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
        insertionSort(a, num);

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
void insertionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    // selection sort 알고리즘 구현
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        for (j = i; j > 0; j--)
        {
            countCmpOps++;
            if (a[j - 1] > tmp)
            {
                countSwaps++;
                a[j] = a[j - 1];
            }
            else
            {
                break;
            }
        }
        a[j] = tmp;
    }

    printf("%d %d ", countCmpOps, countSwaps);
}
