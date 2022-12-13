#include <iostream>
using namespace std;

int cheeze[4][4] = {{160, 150, 600, 160}, {8, 3, 6, 4}};
int price[4];
int idx = 0;

int findMax(int a[])
{
    int max = 0;
    for (int i = 0; i < 4; i++)
    {
        if (max < price[i])
        {
            max = price[i];
            idx = i;
        }
    }
    return max;
}

int main()
{
    int size = 10;
    int ret = 0;

    for (int i = 0; i < 4; i++)
    {
        price[i] = cheeze[0][i] / cheeze[1][i];
    }

    int max = findMax(price);
    while (size > 0 && cheeze[1][idx] != 0)
    {
        size--;
        cheeze[1][idx]--;

        ret += price[idx];

        if (size == 0)
            break;

        if (cheeze[1][idx] == 0)
            price[idx] = 0;

        max = 0;
        max = findMax(price);
    }

    printf("%d", ret);
    return 0;
}