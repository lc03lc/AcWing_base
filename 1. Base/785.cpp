#include <iostream>
#include <vector>
using namespace std;

int nums[100002];

void quickSort(int q[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = (start + end) / 2;
    int base = q[pivot];
    int left = start;
    int right = end;
    swap(q[start], q[pivot]);

    while (left < right)
    {
        while (left < right && q[right] > base)
        {
            right--;
        }
        if (left < right)
        {
            q[left++] = q[right];
        }
        while (left < right && q[left] < base)
        {
            left++;
        }
        if (left < right)
        {
            q[right--] = q[left];
        }
    }
    q[left] = base;
    quickSort(q, start, left - 1);
    quickSort(q, left + 1, end);
}

int main()
{
    int N;
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        nums[i] = tmp;
    }
    quickSort(nums, 0, N - 1);

    for (int i = 0; i < N; ++i)
    {
        cout << nums[i] << " ";
    }
}
