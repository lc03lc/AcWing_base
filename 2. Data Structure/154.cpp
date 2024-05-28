#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int MAX = 1e6 + 10;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr(MAX);
    vector<int> vec1, vec2;
    deque<int> q;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        while (q.size() && q.back() > arr[i])
        {
            q.pop_back();
        }
        q.push_back(arr[i]);

        if (i - M >= 0 && q.front() == arr[i - M])
        {
            q.pop_front();
        }

        if (i >= M-1)
        {
            cout << q.front() << " ";
        }
    }

    q.clear();
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        while (q.size() && q.back() < arr[i])
        {
            q.pop_back();
        }
        q.push_back(arr[i]);

        if (i - M >= 0 && q.front() == arr[i - M])
        {
            q.pop_front();
        }

        if (i >= M-1)
        {
            cout << q.front() << " ";
        }
    }
}