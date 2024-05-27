#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> vec;
    vector<int> vec2;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        vec2.push_back(tmp);
    }

    int l = 0;
    int r = m - 1;
    while (l < n && r >= 0)
    {
        if (vec[l] + vec2[r] > x)
        {
            r--;
        }
        else if (vec[l] + vec2[r] < x)
        {
            l++;
        }
        else
        {
            cout << l << " " << r;
            break;
        }
    }
}
