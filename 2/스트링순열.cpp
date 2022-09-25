#include <iostream>
using namespace std;

void permuteString(char *str, int begin, int end);
void permute(char *str);

int cnt = 0;

int main()
{
    int t;
    cin >> t;

    char a[10];
    for (int i = 0; i < t; i++)
    {
        cin >> a;
        permute(a);
        cout << cnt << "\n";
        cnt = 0;
    }

    return 0;
}

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void permuteString(char *str, int begin, int end)
{
    int i;
    int range = end - begin;

    if (range == 1)
    {
        int sum = 0;
        for (int j = 0; str[j] != '\0'; j++)
        {
            if (j % 2 == 0)
            {
                sum += int(str[j] - int('a'));
            }
            else
            {
                sum -= (int(str[j] - int('a')));
            }
        }
        if (sum > 0)
        {
            cnt++;
        }
    }
    else
    {
        for (i = 0; i < range; i++)
        {
            swap(&str[begin], &str[begin + i]);
            permuteString(str, begin + 1, end);
            swap(&str[begin], &str[begin + i]);
        }
    }
}

void permute(char *str)
{
    int strlen = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        strlen = i + 1;
    }
    permuteString(str, 0, strlen);
}