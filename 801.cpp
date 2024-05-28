#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> vec;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
    }

    for (auto n : vec)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 2;
            n = n / 2;
        }
        cout << sum  << " ";
    }
}