#include <iostream>
using namespace std;

int v[1010], w[1010];
int dp[1010];
// int dp[1010][1010];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    // 二维dp
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         if (v[i] > j)
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
    //         }
    //     }
    // }

    // 一维dp
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[m];
}