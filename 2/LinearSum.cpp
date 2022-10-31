#include <iostream>
using namespace std;

int sum(int a[], int n);

int main()
{
    int a[5] = {3, 6, 5, 2, 4};
    cout << sum(a, 5);
    return 0;
}

int sum(int a[], int n)
{
    if (n == 1)
        return a[0];
    else
        return sum(a, n - 1) + a[n - 1];
}