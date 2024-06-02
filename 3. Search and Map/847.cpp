#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 2e5 + 10;
bool st[MAX];
int d[MAX];
int h[MAX]; // 邻接表
int e[MAX];
int ne[MAX];
int idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int main()
{
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    queue<int> q;
    q.push(1);
    d[1] = 0;
    st[1] = 1;

    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = h[k]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!st[j])
            {
                q.push(j);
                st[j] = 1;
                d[j] = d[k] + 1;
            }
        }
    }

    cout << d[n];
}