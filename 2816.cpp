#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec1;
    vector<int> vec2;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vec1.push_back(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        vec2.push_back(tmp);
    }

    int l1 = 0, l2 = 0;
    while (l2 < m && l1 < n)
    {
        if (vec2[l2] == vec1[l1])
        {
            l1++;
        }
        l2++;
    }

    if (l1 == n)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}