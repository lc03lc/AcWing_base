#include <iostream>
using namespace std;

const int MAX = 5e4 + 10;
int p[MAX];
int t[3] = {0}; // 存每一类的根节点
int h[3] = {1, 2, 0};
int h2[3] = {2, 0, 1};

int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main()
{
    int sum = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int d, b, c;
        cin >> d >> b >> c;
        if (b > n || c > n)
        {
            sum++;
            continue;
        }
        if (d == 1)
        {
            if (b == c)
            {
                continue;
            }
            else
            {
                int root_b = find(b);
                int root_c = find(c);

                int t1 = -1, t2 = -1;
                for (int j = 0; j < 3; j++)
                {
                    t1 = (t[j] == root_b) ? j : t1;
                    t2 = (t[j] == root_c) ? j : t2;
                }

                if (t1 == -1 && t2 == -1)
                {
                    p[root_c] = root_b;
                }
                else if (t1 == -1)
                {
                    p[root_c] = root_b;
                }
                else if (t2 == -1)
                {
                    p[root_b] = root_c;
                }
                else if (t1 == t2)
                {
                    continue;
                }
                else
                {
                    sum += 1;
                }
            }
        }
        else
        {
            if (b == c)
            {
                sum++;
            }
            else
            {
                int root_b = find(b);
                int root_c = find(c);
                if (root_b == root_c)
                {
                    sum++;
                }
                else if (t[0] == 0 && t[1] == 0 && t[2] == 0)
                {
                    t[0] = root_b;
                    t[1] = root_c;
                }
                else
                {
                    int t1 = -1, t2 = -1;
                    for (int j = 0; j < 3; j++)
                    {
                        t1 = (t[j] == root_b) ? j : t1;
                        t2 = (t[j] == root_c) ? j : t2;
                    }
                    if (t1 != -1 && t2 != -1)
                    {
                        if (h[t1] == t2)
                        {
                            continue;
                        }
                        else
                        {
                            sum++;
                        }
                    }
                    else if (t1 != -1)
                    {
                        if (t[h[t1]] == 0)
                        {
                            t[h[t1]] = root_c;
                        }
                        else
                        {
                            p[root_c] = t[h[t1]];
                        }
                    }
                    else if (t2 != -1)
                    {
                        if (t[h2[t2]] == 0)
                        {
                            t[h2[t2]] = root_b;
                        }
                        else
                        {
                            p[root_b] = t[h2[t2]];
                        }
                    }
                    else
                    {
                        
                    }
                }
            }
        }
    }
    cout << sum;
}