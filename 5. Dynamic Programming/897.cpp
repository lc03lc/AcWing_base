#include <iostream>
using namespace std;

const int MAX = 1010;
int dp[MAX][MAX];
char A[MAX], B[MAX];

int main()
{
    int n, m;
    cin >> n >> m >> A+1 >> B+1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m];
}