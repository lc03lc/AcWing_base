#include <iostream>
using namespace std;
const int MAX = 1e5 + 10;

int p[MAX], s[MAX];
int P = 131;

int query(int l, int r)
{
    return s[r] - s[l-1] * p[r - l + 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    string x;
    cin >> x;
    p[0] = 1;
    s[0] = 0;

    for (int i = 0; i < n; i++)
    {
        p[i + 1] = p[i] * P;
        s[i + 1] = s[i] * P + x[i];
    }

    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (query(l1, r1) == query(l2, r2))
            printf("Yes\n");
        else
            printf("No\n");
    }
}