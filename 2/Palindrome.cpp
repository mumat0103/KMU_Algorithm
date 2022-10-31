#include <iostream>
#include <string.h>
using namespace std;

int check(char str[], int first, int last);

int main()
{
    char line[256] = "malayalam";
    printf("%d \n", check(line, 0, strlen(line) - 1));
    return 0;
}

int check(char str[], int first, int last)
{
    if (last <= first)
        return 1;
    else if (str[first] != str[last])
        return 0;
    else
        return check(str, first + 1, last - 1);
}
