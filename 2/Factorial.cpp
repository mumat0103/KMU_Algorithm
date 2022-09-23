#include <iostream>
using namespace std;

long long facto(int n);

long long ans;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        ans = 1;
        cout << facto(n) << "\n";
    }

    return 0;
}

long long facto(int n)
{
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
        ans %= 10000000;
        while (ans % 10 == 0)
            ans /= 10;
    }
    return ans % 1000;
}