#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2010;

vector<int> v, w;
int dp[MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    
    v.push_back(0);
    w.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            v.push_back(a * k);
            w.push_back(b * k);
            s -= k;
            k = k * 2;
        }
        if (s)
        {
            v.push_back(a * s);
            w.push_back(b * s);
        }
    }

    for (int i = 1; i <= v.size()-1; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[m];
}