#include <iostream>
#include <vector>

using namespace std;

void merge(int source[], int tmp[], int start,int mid, int end)
{
    
}

void mergeSort(int source[], int tmp[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(source, tmp, start, mid);
        mergeSort(source, tmp, mid+1, end);
        merge(source, tmp, start, mid, end);
    }
}