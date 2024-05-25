#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    const int N = 1e6 + 10;

    vector<int> vec(N);
    string a, b;
    cin >> a >> b;
    vector<int> A(N), B(N);

    int p1 = 0, p2 = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A[p1] = (a[i] - '0');
        p1++;
    }

    for (int i = b.size() - 1; i >= 0; i--)
    {
        B[p2] = (b[i] - '0');
        p2++;
    }

    int over = 0;
    for (int i = 0; i < N; i++)
    {
        int ans = A[i] + B[i] + over;
        if (ans >= 10)
        {
            vec[i] = ans - 10;
            over = 1;
        }
        else
        {
            vec[i] = ans;
            over = 0;
        }
    }

    int pos;
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        if (vec[i] != 0)
        {
            pos = i;
            break;
        }
    }

    for (int i = pos; i >= 0; i--)
    {
        cout << vec[i];
    }
}