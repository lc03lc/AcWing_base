#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 10;
int h[MAX]; // 邻接表
int idx;
int ne[MAX * 2];
int e[MAX * 2];
int n;
bool st[MAX];
int ans = MAX;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int dfs(int u)
{
    int res = 0;
    st[u] = 1;
    int sum = 1;
    for (int i = h[u]; i != -1; i=ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            sum += s;
            res = max(res, s);
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);

    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1);
    cout << ans;
}