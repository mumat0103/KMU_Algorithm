#include <iostream>
using namespace std;

#define MAX_LEN 101

void reverseArray(char *a, int i, int j);

int main()
{
    int t;
    cin >> t;

    char a[MAX_LEN];

    for (int i = 0; i < t; i++)
    {
        cin >> a;
        int index = 0;
        for (int j = 0; a[j] != '\0'; j++)
        {
            index = j;
        }
        reverseArray(a, 0, index);
        cout << a << "\n";
    }
}

void swap(char *a, int i, int j)
{
    char tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void reverseArray(char *a, int i, int j)
{
    if (i < j)
    {
        swap(a, i, j);
        reverseArray(a, i + 1, j - 1);
    }
}