#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;

    stack<int> q;
    while (N--)
    {
        int tmp;
        cin >> tmp;
        int t = -1;
        while (!q.empty())
        {
            int k = q.top();
            if (k < tmp)
            {
                t = k;
                break;
            }
            q.pop();
        }
        q.push(tmp);
        cout << t << " ";
    }
}