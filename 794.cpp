#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
const int N = 1e6 + 10, M = 5;

int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    vector<int> vec;
    for (int i = 0; i < a.size(); i++)
    {
        A.push_back(a[i] - '0');
    }

    int res2 = 0;
    int p = 0, tmp = b, cur = 0;
    while (tmp)
    {
        tmp /= 10;
        p++;
    }
    if (p > A.size())
    {
        cout << 0 << "\n"
             << a;
    }
    else
    {
        for (int i = 0; i < p; i++)
        {
            cur += pow(10, (p - i - 1)) * A[i];
        }

        for (int i = p - 1; i < A.size(); i++)
        {
            vec.push_back(cur / b);
            res2 = cur % b;
            cur = res2;
            cur *= 10;
            cur += A[i + 1];
        }

        int pos = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] != 0)
            {
                pos = i;
                break;
            }
        }
        for (int i = pos; i < vec.size(); i++)
        {
            cout << vec[i];
        }
        cout << "\n"
             << res2;
    }
}
