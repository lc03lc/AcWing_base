#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    int res = 0;

    while (q.size() != 1)
    {
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();
        int t = t1 + t2;
        res += t;
        q.push(t);
    }

    cout << res;
}