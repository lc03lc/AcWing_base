#include <iostream>
#include <vector>
using namespace std;

const int n = 100010;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> vec(n);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        vec[i] = tmp;
    }

    vector<int> sum(n);
    sum[0] = 0;
    sum[1] = vec[0];
    for (int i = 2; i < n; i++)
    {
        sum[i] = sum[i-1] + vec[i-1];
    }
    for(int i=0; i<M; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << '\n';
    }
}