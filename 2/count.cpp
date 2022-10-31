#include <iostream>
using namespace std;

void countUp(int n);
void countDw(int n);
int main()
{
    countUp(4);
    countDw(4);
}

void countUp(int n)
{
    if (n > 0)
        countUp(n - 1);
    printf("%d \n", n);
}
void countDw(int n)
{
    printf("%d \n", n);
    if (n > 0)
        countDw(n - 1);
}