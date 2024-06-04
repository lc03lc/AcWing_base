#include <iostream>

using namespace std;

const int MAX = 510;
int m[MAX][MAX];
int dp[MAX][MAX];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> m[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        dp[n][i] = m[n][i];
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + m[i][j];
        }
    }

    cout << dp[1][1];
}