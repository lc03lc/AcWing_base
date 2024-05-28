#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 10;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> vec(MAX);
    vector<int> vec2(MAX);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &vec[i]);
        vec2[i] = vec[i] - vec[i-1];
    }

    int l, r, c;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &l, &r, &c);
        vec2[l] += c;
        vec2[r+1] -= c;
    }

    for(int i=1; i<=N; i++)
    {
        vec[i] = vec[i-1] + vec2[i];
        printf("%d ", vec[i]);   
    }

}
