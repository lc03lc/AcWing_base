#include <iostream>
#include <cstring>

using namespace std;

int g[210][210];
int INF = 0x3f3f3f3f;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(c, g[a][b]);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[i][j]);
            }
        }
    }

    while (k--)
    {
        int a, b;
        cin >> a >> b;
        int ans = g[a][b];
        if (g[a][b] > INF / 2)
        {
            cout << "impossible\n";
        }
        else
        {
            cout << g[a][b] << "\n";
        }
    }
}