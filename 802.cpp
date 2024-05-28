#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 10;
vector<pair<int, int>> vec;
vector<int> ord;
vector<int> a(MAX);
vector<int> s(MAX);

vector<pair<int, int>> query;

int find(int x)
{
    int l = -1, r = ord.size();
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (ord[mid] > x)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return l + 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        vec.push_back({x, c});
        ord.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        ord.push_back(l);
        ord.push_back(r);
    }

    sort(ord.begin(), ord.end());
    ord.erase(unique(ord.begin(), ord.end()), ord.end());

    for (auto item : vec)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= ord.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    for(auto i: query)
    {
        int l = find(i.first);
        int r = find(i.second);
        cout << s[r] - s[l-1] << "\n";
    }
}