#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int arr[N];
int ss[N];

int find(int x)
{
    if(arr[x]!=x)
    {
        arr[x] = find(arr[x]);
    }
    return arr[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
    {
        arr[i] = i;
        ss[i] = 1;
    }
    
    for(int i=0; i<m; i++)
    {
        string ch;
        cin >> ch;
        if(ch=="C")
        {
            int a, b;
            cin >> a >> b;
            int root_a = find(a);
            int root_b = find(b);
            if(root_a != root_b) {
                arr[root_a] = root_b;
                ss[root_b] += ss[root_a];
            }
        }else if(ch=="Q1")
        {
            int a, b;
            cin >> a >> b;
            if(find(a)==find(b))
            {
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }else{
            int a;
            cin >> a;
            cout << ss[find(a)] << "\n";   
        }
    }
}