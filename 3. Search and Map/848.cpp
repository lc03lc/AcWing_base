#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 2e5 + 10;
int d[MAX]; // 记录入度
int h[MAX]; // 邻接表
int e[MAX];
int ne[MAX];
int idx;
vector<int> ans;

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

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }
    }

    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int j = h[k]; j != -1; j = ne[j])
        {
            int kk = e[j];
            d[kk]--;
            if (d[kk] == 0)
            {
                q.push(kk);
                ans.push_back(kk);
            }
        }
    }

    if (ans.size() != n)
    {
        cout << "-1";
    }
    else
    {
        for (int x : ans)
        {
            cout << x << " ";
        }
    }
}