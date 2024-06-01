#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 110;
int map[MAX][MAX];
int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};
int d[MAX][MAX];
int n, m;

int bfs()
{
    memset(d, -1, sizeof d);
    queue<pair<int, int>> q;
    q.push({0, 0});
    d[0][0] = 0;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x_ = p.first + x[i];
            int y_ = p.second + y[i];
            if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && !map[x_][y_] && d[x_][y_] ==-1)
            {
                d[x_][y_] = d[p.first][p.second] + 1;
                q.push({x_, y_});
            }
        }
    }

    return d[n-1][m-1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    cout << bfs();
}