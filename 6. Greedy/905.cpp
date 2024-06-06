#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10010;
vector<pair<int, int>> vec;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({b, a});
    }

    sort(vec.begin(), vec.end());

    int p = vec[0].first;
    int ans = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        if (p < vec[i].second || p > vec[i].first)
        {
            ans++;
            p = vec[i].first;
        }
    }

    cout << ans;
}