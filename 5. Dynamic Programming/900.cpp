#include <iostream>

using namespace std;

const int MAX = 1010;
int dp[MAX][MAX];
int m = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) // 前i个数中选择
    {
        for (int j = 1; j <= n; j++) // 正好和为j
        {
            int s = 0;
            while (j - s * i >= 0)
                s++;
            for (int k = 0; k < s; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k * i]) % m;
        }
    }

    cout << dp[n][n];
}