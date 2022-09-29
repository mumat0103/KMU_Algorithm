#include <iostream>
using namespace std;

int p(int x, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, n;
        cin >> a >> n;
        cout << p(a, n) % 1000 << "\n";
    }
    return 0;
}

int p(int x, int n)
{
    int y;

    if (n == 0)
        return 1;
    else if (n % 2 == 1)
    {
        y = p(x, (n - 1) / 2) % 1000;
        return (x * y * y) % 1000;
    }
    else
    {
        y = p(x, n / 2) % 1000;
        return (y * y) % 1000;
    }
}