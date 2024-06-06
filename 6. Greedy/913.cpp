#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int LLI;

int main()
{
    int n;
    cin >> n;

    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        q.push_back(tmp);
    }

    sort(q.begin(), q.end());

    LLI res = 0;
    for(int i=1; i<n; i++)
    {
        res += q[i-1] * (n-i);
    }

    cout << res;
}