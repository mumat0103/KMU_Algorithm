// 20180269 천성규
#include <iostream>
using namespace std;
#define MAX_SIZE 1100
#define R 3

int DFA[R][MAX_SIZE];
int patternlen = 0, zero = 0, match = 0;

int strlen(char a[])
{
    int len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        len = i + 1;

    return len;
}

void constructDFA(char pattern[])
{
    int patLength = strlen(pattern);
    int X = 0;
    DFA[pattern[0] - 'A'][0] = 1;
    for (int i = 1; i < patLength; i++)
    {
        for (int c = 0; c < R; c++)
            DFA[c][i] = DFA[c][X];

        DFA[pattern[i] - 'A'][i] = i + 1;
        X = DFA[pattern[i] - 'A'][X];
    }

    for (int c = 0; c < R; c++)
        DFA[c][patLength] = DFA[c][X];
}

void solveDFA(char text[])
{
    int txtLength = strlen(text);
    for (int i = 0, j = 0; text[i] != '\0'; i++)
    {
        j = DFA[text[i] - 'A'][j];
        if (j == patternlen)
        {
            match++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char pattern[1100];
        cin >> pattern;
        patternlen = strlen(pattern);
        constructDFA(pattern);

        char text[1100];
        cin >> text;

        solveDFA(text);
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j <= patternlen; j++)
            {
                if (DFA[i][j] != 0)
                {
                    zero++;
                }
            }
        }
        cout << zero << " " << match << endl;
        zero = 0;
        match = 0;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j <= patternlen; j++)
            {
                DFA[i][j] = 0;
            }
        }
    }
    return 0;
}