#include <iostream>
using namespace std;
const int MAX = 15;
bool col[MAX], lr[MAX * 2], rl[MAX * 2];
int path[MAX];
int n;

void dfs(int u)
{
    if (u == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == path[i])
                {
                    cout << "Q";
                }
                else
                {
                    cout << ".";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int j = 1; j <= n; j++)
    {
        int _lr = n - j + u;
        int _rl = u + j - 1;

        if (!col[j] && !lr[_lr] && !rl[_rl])
        {
            path[u] = j;
            col[j] = 1;
            lr[_lr] = 1;
            rl[_rl] = 1;

            dfs(u + 1);
            col[j] = 0;
            lr[_lr] = 0;
            rl[_rl] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
}