#include <iostream>
using namespace std;

void baseConversion(int n, int base);

int main()
{
    int num = 10;
    baseConversion(num, 2);
    return 0;
}

void baseConversion(int n, int base)
{
    static char baseTable[] = "0123456789abcdef";

    if (n >= base)
        baseConversion(n / base, base);
    printf("%c \n", baseTable[n % base]);
}