#include <iostream>
using namespace std;

#define MAX_SIZE 11000
int balance(int a[], int n);
int KG[7] = {100, 50, 20, 10, 5, 2, 1};
int main()
{
    int t;
    int n;
    int a[MAX_SIZE];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << balance(a, n) << "\n";
    }
    return 0;
}

int balance(int a[], int n)
{
    int left = 0;
    int right = 0;

    for (int i = 0; i < n; i++)
    {
        if (left <= right)
            left += a[i];
        else
            right += a[i];
    }

    int sub = 0;

    if (left >= right)
        sub = left - right;
    else
        sub = right - left;

    int answer = 0;

    if (sub == 0)
        return 0;
    for (int i = 0; i < 7; i++)
    {
        answer += sub / KG[i];
        sub %= KG[i];
    }

    return answer;
}