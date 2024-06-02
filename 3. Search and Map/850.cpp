#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1.5e5 + 10;

typedef pair<int, int> PII;
int h[MAX], e[MAX], ne[MAX], w[MAX];
int idx;
int dist[MAX];
int st[MAX];

int add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int main()
{
    memset(h, -1, sizeof h);
    memset(dist, 0x3f3f3f3f, sizeof dist);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (q.size())
    {
        PII k = q.top();
        q.pop();
        int dis = k.first;
        int point = k.second;
        if (st[point])
        {
            continue;
        }
        st[point] = 1;

        for (int i = h[point]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[point] + w[i])
            {
                dist[j] = dist[point] + w[i];
            }
            q.push({dist[j], j});
        }
    }

    if (dist[n] == 0x3f3f3f3f)
    {
        cout << "-1";
    }
    else
    {
        cout << dist[n];
    }
}