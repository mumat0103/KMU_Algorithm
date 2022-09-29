#include <iostream>
#define MAX_SIZE 16
using namespace std;
void Hanoi(int n, int a, int b, int c);
int stack[MAX_SIZE];
int top;

void Hanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        Hanoi(n - 1, a, c, b);
        if (c == 3)
        {
            top++;
            stack[top] = n;
            printf("%d ", n);
        }
        else if (a == 3)
        {
            top--;
            if (top == -1)
                printf("%d ", 0);
            else
                printf("%d ", stack[top]);
        }
        Hanoi(n - 1, b, a, c);
    }
}
int main()
{
    int t;
    cin >> t;

    int numDisks;

    for (int i = 0; i < t; i++)
    {
        cin >> numDisks;
        top = -1;
        Hanoi(numDisks, 1, 2, 3);
        cout << "\n";
    }
    return 0;
}