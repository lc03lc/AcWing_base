#include <iostream>
#include <vector>
using namespace std;

int dp[1010];
vector<int> v, w;

int main()
{
    int n, m;
    cin >> n >> m;
    int k = 0;
    v.push_back(0);
    w.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        while(c--)
        {
            v.push_back(a);
            w.push_back(b);
            k++;
        }
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[m];
}