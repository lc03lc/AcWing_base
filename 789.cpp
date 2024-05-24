#include <iostream>

void binSearch(int arr[], int n, int q)
{
    int l = -1, r = n;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (arr[mid] < q)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if (r == n || arr[r] != q)
    {
        printf("-1 -1\n");
    }
    else
    {
        int min = r;
        l = -1, r = n;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (arr[mid] <= q)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        int max = l;
        printf("%d %d\n", min, max);
    }
}

int main()
{
    int arr[100002];
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k, start, end;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &k);
        binSearch(arr, n, k);
    }
}