#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 10;
int e[MAX];
int ne[MAX];
int w[MAX];
int h[MAX];
int idx;
int dist[MAX];
bool st[MAX];
int cnt[MAX];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx;
    idx++;
}

int main()
{
    memset(h, -1, sizeof h);
    // memset(dist, 0x3f3f3f3f, sizeof dist);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = 1;
    }

    while (q.size())
    {
        int k = q.front();
        q.pop();
        st[k] = 0;

        for (int i = h[k]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[k] + w[i])
            {
                dist[j] = dist[k] + w[i];
                cnt[j] = cnt[k] + 1;
                if (cnt[j] >= n)
                {
                    cout << "Yes";
                    exit(0);
                }
                if (!st[j])
                {
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }

    cout << "No";
}