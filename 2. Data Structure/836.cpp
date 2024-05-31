#include <iostream>
using namespace std;

const int MAX = 1e5 + 10;
int p[MAX];

int find(int x)
{
    if (x != p[x])
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if (ch == 'M')
        {
            p[find(b)] = find(a);
        }
        else
        {
            if (find(a) == find(b))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
}
