#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int N = 1e6 + 10, M = 5;

vector<int> add(vector<int> A, vector<int> B)
{
    string res = "";
    vector<int> vec(N);

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

    return vec;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A(N), B(M);
    vector<int> vec(N);

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

    vector<int> result(N);

    int over = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int ans = B[i] * A[j] + over;
            vec[j] = ans % 10;
            over = ans / 10;
        }
        for (int z = 0; z < i; z++)
        {
            vec.insert(vec.begin(), 0);
        }
        result = add(result, vec);
    }

    int pos = 0;
    for (int i = result.size() - 1; i >= 0; i--)
    {
        if (result[i] != 0)
        {
            pos = i;
            break;
        }
    }

    for (int i = pos; i >= 0; i--)
    {
        cout << result[i];
    }
}