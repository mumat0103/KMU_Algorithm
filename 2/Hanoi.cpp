#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

void Hanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        Hanoi(n - 1, a, c, b);
        if (c == 3)
        {
            s.push(n);
            printf("%d ", s.top());
        }
        else if (a == 3)
        {
            if (!s.empty())
            {
                s.pop();
            }
            printf("%d ", s.top());
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
        s.push(0);
        cin >> numDisks;
        Hanoi(numDisks, 1, 2, 3);
        cout << "\n";
    }

    return 0;
}