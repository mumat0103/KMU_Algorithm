#include <iostream>
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX_SIZE 11000

int balance(int a[], int n);

int w[7] = {1, 2, 5, 10, 20, 50, 100};
int d[11000000];
int a[MAX_SIZE];

int main()
{
    int t;
    int n, answer;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        answer = balance(a, n);
        cout << answer << "\n";
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

    if (left > right)
        sub = left - right;
    else if (right > left)
        sub = right - left;

    for (int i = 0; i < sub + 1; i++)
        d[i] = 11000000;

    d[0] = 0;
    for (int i = 0; i < 7; i++)
        for (int j = w[i]; j < sub + 1; j++)
        {
            d[j] = MIN(d[j], d[j - w[i]] + 1);
        }
    int answer = d[sub];
    return answer;
}