#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    vector<vector<int>> vec(N);
    vector<vector<int>> vec2(N);

    for (int i = 0; i < N; i++)
    {
        vector<int> tmp(N);
        vec[i] = tmp;
        vec2[i] = tmp;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &vec[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            vec2[i][j] = vec[i][j] - vec[i - 1][j] - vec[i][j - 1] + vec[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        vec2[x1][y1] += c;
        vec2[x2 + 1][y1] -= c;
        vec2[x1][y2 + 1] -= c;
        vec2[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            vec[i][j] = vec2[i][j] + vec[i - 1][j] + vec[i][j - 1] - vec[i - 1][j - 1];
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
}