#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100010];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);

    int l=0, r = n-1;
    int res = 0;
    while(l+2<r)
        res += a[l++]-a[r--];
    cout << res;
}