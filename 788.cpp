#include <iostream>

using namespace std;
long long Count = 0;

void merge(int source[], int tmp[], int start, int mid, int end)
{
    int i = start, j = mid + 1;
    int k = start;
    while (i != mid + 1 && j != end + 1)
    {
        if (source[i] <= source[j])
        {
            tmp[k++] = source[i++];
        }
        else
        {
            Count += (mid - i + 1);
            tmp[k++] = source[j++];
        }
    }
    while (i != mid + 1)
    {
        tmp[k++] = source[i++];
    }
    while (j != end + 1)
    {
        tmp[k++] = source[j++];
    }
    for (int i = start; i < end + 1; i++)
    {
        source[i] = tmp[i];
    }
}

void mergeSort(int source[], int tmp[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(source, tmp, start, mid);
        mergeSort(source, tmp, mid + 1, end);
        merge(source, tmp, start, mid, end);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int arr[100002];
    int arr_t[100002];
    for (int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, arr_t, 0, N - 1);
    printf("%lld", Count);
}
