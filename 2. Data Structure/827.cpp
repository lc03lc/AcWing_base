#include <iostream>
using namespace std;

const int N = 100000 + 10;
int e[N], re[N], le[N];
int idx, phead, pend;

void init()
{
    phead = -1;
    pend = -1;
    idx = 0;
}

void add_to_left(int x)
{
    e[idx] = x;
    re[idx] = phead;
    le[idx] = -1;
    le[phead] = idx;
    phead = idx;
    idx++;
    if (pend == -1)
    {
        pend = phead;
    }
}

void add_to_right(int x)
{
    e[idx] = x;
    le[idx] = pend;
    re[idx] = -1;
    re[pend] = idx;
    pend = idx;
    idx++;
    if (phead == -1)
    {
        phead = pend;
    }
}

void del(int k)
{
    if (k != phead)
    {
        re[le[k]] = re[k];
    } else{
        phead = re[k];
    }
    if (k != pend)
    {
        le[re[k]] = le[k];
    } else {
        pend = le[k];
    }
}

void add_to_k_left(int k, int x)
{
    if (k == phead)
    {
        add_to_left(x);
    }
    else
    {
        e[idx] = x;
        re[idx] = k;
        le[idx] = le[k];
        re[le[k]] = idx;
        le[k] = idx;
        idx++;
    }
}

void add_to_k_right(int k, int x)
{
    if (k == pend)
    {
        add_to_right(x);
    }
    else
    {
        e[idx] = x;
        le[idx] = k;
        re[idx] = re[k];
        le[re[k]] = idx;
        re[k] = idx;
        idx++;
    }
}

int main()
{
    init();

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string ch;
        cin >> ch;
        if (ch == "IL")
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            add_to_k_left(tmp1 - 1, tmp2);
        }
        else if (ch == "IR")
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            add_to_k_right(tmp1 - 1, tmp2);
        }
        else if (ch == "L")
        {
            int tmp;
            cin >> tmp;
            add_to_left(tmp);
        }
        else if (ch == "R")
        {
            int tmp;
            cin >> tmp;
            add_to_right(tmp);
        }
        else
        {
            int tmp;
            cin >> tmp;
            del(tmp-1);
        }
    }

    while (1)
    {
        if (phead == -1)
        {
            break;
        }
        cout << e[phead] << " ";
        phead = re[phead];
    }
}