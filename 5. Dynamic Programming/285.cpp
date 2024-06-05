#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 6010;

int e[MAX], ne[MAX], h[MAX], idx;
int dp[MAX][2];
int happy[MAX];
bool father[MAX];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void dfs(int u)
{
    dp[u][1] = happy[u];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0];
    }
}

int main()
{
    memset(h, -1, sizeof h);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> happy[i];

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        father[a] = 1;
        add(b, a);
    }

    int k = 1;
    while (father[k])
        k++;

    dfs(k);
    cout << max(dp[k][0], dp[k][1]);
}