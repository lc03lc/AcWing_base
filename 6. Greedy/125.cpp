#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int LLI;
const int MAX = 50010;
vector<pair<LLI, LLI>> vec;
LLI s[MAX];

bool compare(pair<LLI, LLI> a, pair<LLI, LLI> b)
{
    return a.first + a.second > b.first + b.second;
}

int main()
{
    int n;
    cin >> n;
    vec.push_back({0, 0});
    for (int i = 0; i < n; i++)
    {
        LLI a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    sort(vec.begin() + 1, vec.end(), compare);

    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + vec[i].first;
    }
    s[n + 1] = s[n];

    LLI res = -1e10;
    for (int i = 2; i <= n + 1; i++)
    {
        res = max(res, s[n] - s[i - 1] - vec[i - 1].second);
    }

    cout << res;
}