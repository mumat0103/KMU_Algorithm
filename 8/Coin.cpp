#include <iostream>
using namespace std;

int coin[6] = {100, 63, 50, 25, 10, 1};

int main()
{
    int money;
    cin >> money;

    int ret;

    for (int i = 0; i < 6; i++)
    {
        if (money >= coin[i])
        {
            ret += money / coin[i];
            money %= coin[i];
        }
    }
    printf("%d", ret);

    return 0;
}