#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > vec;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l ,r;
        cin >> l >> r;
        vec.push_back({l, r});
    }

    sort(vec.begin(), vec.end());

    int sum = n;
    int end = vec[0].second;
    for(int i=0; i<vec.size()-1; i++)
    {
        if(end >= vec[i+1].first)
        {
            sum--;
            end = end > vec[i+1].second ? end : vec[i+1].second;
        } else{
            end = vec[i+1].second;
        }
    }

    cout << sum;
}