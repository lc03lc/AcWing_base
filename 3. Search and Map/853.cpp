#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10010;
int dist[MAX], backup[MAX];

struct Edge
{
    int a;
    int b;
    int c;
} edges[MAX];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a;
            int b = edges[j].b;
            int c = edges[j].c;

            dist[b] = min(dist[b], backup[a] + c);
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2)
    {
        cout << "impossible";
    }
    else
    {
        cout << dist[n];
    }
}
