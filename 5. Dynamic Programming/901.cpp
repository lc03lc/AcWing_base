#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 310;
int s[MAX][MAX];
int dp[MAX][MAX];
int x[4] = {0, 0, 1, -1}, y[4] = {1, -1, 0, 0};
int n, m;

int find(int a, int b)
{
    int &v = dp[a][b];
    if (v != -1)
        return v;
    v = 1;
    for (int i = 0; i < 4; i++)
    {
        int dx = x[i] + a;
        int dy = y[i] + b;
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && s[a][b] > s[dx][dy])
        {
            v = max(dp[a][b], find(dx, dy) + 1);
        }
    }
    return v;
}

int main()
{

    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = max(res, find(i, j));
        }
    }
    cout << res;
    return 0;
}