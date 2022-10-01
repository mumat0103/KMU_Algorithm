#include <iostream>
using namespace std;

int fib(int n);

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << fib(n) << "\n";
    }

    return 0;
}

int fib(int n)
{
    if (n <= 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}
