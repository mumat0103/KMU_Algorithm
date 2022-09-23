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

        int results = fib(n);
        cout << results << "\n";
        results = 0;
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
