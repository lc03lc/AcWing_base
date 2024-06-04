#include <iostream>
using namespace std;

const int MAX = 1010;
int dp[MAX][MAX];
char A[MAX], B[MAX];

int main()
{
    int n, m;
    cin >> n >> A + 1 >> m >> B + 1;

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (A[i] == B[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }

    cout << dp[n][m];
}