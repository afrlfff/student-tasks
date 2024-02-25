#include <vector>
#include <iostream>
#include "SortFunctions.h"

int GetMinRun(int n)
{
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

void TSMerge(std::vector<int>& A, int low, int mid, int high)
{
    int sizeLeft = mid - low + 1;
    int sizeRight = high - mid;

    std::vector<int> tempLeft(sizeLeft);
    std::vector<int> tempRight(sizeRight);

    for (int i = 0; i < sizeLeft; i++)
        tempLeft[i] = A[low + i];
    for (int i = 0; i < sizeRight; i++)
        tempRight[i] = A[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < sizeLeft && j < sizeRight)
    {
        if (tempLeft[i] <= tempRight[j])
            A[k++] = tempLeft[i++];
        else
            A[k++] = tempRight[j++];
    }
    while (i < sizeLeft)
        A[k++] = tempLeft[i++];
    while (j < sizeRight)
        A[k++] = tempRight[j++];
}

void SortFunctions::TimSort(std::vector<int>& A, int low, int high)
{
    if (low >= high)
        return;
    int size = high - low + 1;

    int minRun = GetMinRun(size);
    for (int i = 0; i < size; i += minRun)
        InsertionSort(A, i, std::min(minRun, size - i) - 1);

    for (int sizeRun = minRun; sizeRun < size; sizeRun *= 2)
    {
        for (int i = 0; i < size; i += 2 * sizeRun)
        {
            int mid = std::min(i + sizeRun - 1, size - 1);
            int right = std::min(i + 2 * sizeRun - 1, size - 1);
            TSMerge(A, i, mid, right);
        }
    }
}