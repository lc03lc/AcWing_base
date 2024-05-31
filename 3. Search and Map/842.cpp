#include <iostream>
using namespace std;

const int MAX = 7;

int path[MAX];
bool st[MAX] = {0};
int n;

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!st[i])
        {
            path[u] = i;
            st[i] = 1;
            dfs(u+1);
            st[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
}