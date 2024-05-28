#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MAX = 1e5 + 10;

int main()
{
    int N;
    cin >> N;
    vector<int> vec(N);
    vector<int> dp(MAX);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    int l = 0, r = 1;
    dp[vec[0]]++;
    int max_ = 1;

    while (r < N)
    {
        if (dp[vec[r]] == 1)
        {
            while (vec[l] != vec[r])
            {
                dp[vec[l]]--;
                l++;
            }
            l++;
        }
        else
        {
            dp[vec[r]] = 1;
        }
        max_ = max(r - l + 1, max_);
        r++;
    }

    cout << max_;
}