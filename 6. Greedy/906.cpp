#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10010;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> rr;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end());

    rr.push(vec[0].second);
    for (int i = 1; i < vec.size(); i++)
    {
        if(vec[i].first > rr.top())
            rr.pop();
        rr.push(vec[i].second);
    }

    cout << rr.size();
}
