#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end());

    int res = 0;
    int k = -1e9 - 10;
    int start = a;

    for (int i = 0; i < n; i++)
    {
        if (vec[i].first <= start)
        {
            if (vec[i].second > k)
            {
                k = vec[i].second;
                if (k >= b)
                {
                    res++;
                    break;
                }
            }
        }
        else
        {
            if (k == start)
            {
                res = -1;
                break;
            }
            else
            {
                res++;
                if (k >= b)
                    break;
                start = k;
                i--;
            }
        }
    }
    if (k < b)
        res = -1;

    cout << res;
}