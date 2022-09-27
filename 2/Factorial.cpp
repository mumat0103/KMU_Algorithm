#include <iostream>
using namespace std;

long long facto(int n);
int facto_recur(int n);

int ans;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        ans = 1;
        cout << facto_recur(n) % 1000 << "\n";
    }

    return 0;
}

int facto_recur(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        ans = n * facto_recur(n - 1);
        while (ans % 10 == 0)
        {
            ans /= 10;
        }
    }
    return ans % 10000;
}