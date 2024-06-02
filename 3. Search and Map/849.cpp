#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
const int M = 1e5 + 10;

// 点多边少用邻接表，点少边多用邻接矩阵
int g[N][N]; // 邻接矩阵
int state[N];
int dist[N];

int main()
{
    memset(g, 0x3f3f3f3f, sizeof g);
    memset(dist, 0x3f3f3f3f, sizeof dist);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!state[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }
        state[t] = 1;

        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    if (dist[n] == 0x3f3f3f3f)
    {
        cout << -1;
    }
    else
    {
        cout << dist[n];
    }
}