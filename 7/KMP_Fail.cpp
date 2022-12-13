// 20180269 천성규
#include <iostream>
using namespace std;

int fail[1100];
int match = 0;

int strlen(char a[])
{
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        len = i + 1;

    return len;
}

void getFail(char pattern[])
{
    int patternLen = strlen(pattern);
    int j = 0;
    for (int i = 1; i < patternLen; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = fail[j - 1];
        if (pattern[i] == pattern[j])
            fail[i] = ++j;
    }
}

void kmp(char text[], char pattern[])
{
    int txtLength = strlen(text);
    int patternLength = strlen(pattern);
    getFail(pattern);

    for (int i = 0, j = 0; text[i] != '\0'; i++)
    {
        while (j > 0 && text[i] != pattern[j])
            j = fail[j - 1];
        if (text[i] == pattern[j])
        {
            if (j == patternLength - 1)
            {
                match++;
                j = fail[j];
            }
            else
                j++;
        }
    }
}

int main()
{
    int t;
    char pattern[1100], text[1100];
    cin >> t;
    while (t--)
    {
        cin >> pattern >> text;
        kmp(text, pattern);

        for (int i = 0; i < strlen(pattern); i++)
            cout << fail[i] << " ";
        cout << '\n';
        cout << match << '\n';

        match = 0;
        for (int i = 0; i < strlen(pattern); i++)
        {
            fail[i] = 0;
        }
    }
    return 0;
}