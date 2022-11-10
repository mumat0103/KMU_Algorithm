// 20180269 천성규
#include <iostream>
using namespace std;

int p[100][100];
int m[100][100];
int a[100];
void cmm(int a[], int n);
void order(int i, int j);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n + 1; i++)
            cin >> a[i];

        for (int i = 1; i < n; i++)
        {
            m[i][i] = 0;
            p[i][i] = 0;
        }

        cmm(a, n + 1);
    }

    return 0;
}

void cmm(int a[], int n)
{

    for (int d = 2; d < n; d++)
    {
        for (int i = 1; i < n - d + 1; i++)
        {
            int j = i + d - 1;
            m[i][j] = 987654321;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    p[i][j] = k;
                }
            }
        }
    }

    order(1, n - 1);
    cout << "\n"
         << m[1][n - 1] << "\n";
}

void order(int i, int j)
{
    if (i == j)
    {
        cout << "M" << i;
        return;
    }

    cout << "(";
    int k = p[i][j];
    order(i, k);
    order(k + 1, j);
    cout << ")";
}