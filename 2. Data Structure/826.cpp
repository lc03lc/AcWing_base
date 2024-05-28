#include <iostream>
using namespace std;

const int N = 100000 + 10;
int e[N], ne[N];
int idx, head;

void init()
{
    head = -1;
    idx = 0;
}

void insert_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void insert_ord(int ord, int x)
{
    e[idx] = x;
    ne[idx] = ne[ord];
    ne[ord] = idx;
    idx++;
}

void delete_ord(int ord)
{
    if (ord == -1)
    {
        head = ne[head];
    }
    else
    {
        ne[ord] = ne[ne[ord]];
    }
}

int main()
{
    init();

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'I')
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            insert_ord(tmp1 - 1, tmp2);
        }
        else if (ch == 'H')
        {
            int tmp;
            cin >> tmp;
            insert_to_head(tmp);
        }
        else
        {
            int tmp;
            cin >> tmp;
            delete_ord(tmp - 1);
        }
    }

    int i = head;
    while (i != -1)
    {
        cout << e[i] << " ";
        i = ne[i];
    }
}