#include <iostream>
using namespace std;

const int MAX = 1e5 + 10;

void up_to_down(int arr[], int len, int root)
{
    int parent = root;
    int child = 2 * parent + 1;
    while (child < len)
    {
        if (child + 1 < len && arr[child + 1] > arr[child])
        {
            child = child + 1;
        }
        if (arr[parent] < arr[child])
        {
            swap(arr[child], arr[parent]);
            parent = child;
            child = child * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void heapSort(int arr[], int len)
{
    int l = len - 1 - 1;
    for (int i = l; i >= 0; i--)
    {
        up_to_down(arr, len, i);
    }

    int end = len-1;
    while (end > 0)
    {
        swap(arr[0], arr[end]);
        up_to_down(arr, end, 0);
        end--;
    }
}

int main()
{
    int arr[MAX];
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);
    for(int i=0; i<m; i++)
    {
        cout << arr[i] << " ";
    }
}