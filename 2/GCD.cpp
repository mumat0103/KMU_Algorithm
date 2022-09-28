#include <iostream>
using namespace std;

int gcd(int a, int b);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        cin >> m >> n;
        cout << gcd(m, n) << "\n";
    }
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}