#include <iostream>
#include <vector>
#include "SortFunctions.h"

int QSPartition(std::vector<int>& A, int low, int high)
{   
    // to avoid stack overflow error on sorted (or back sorted) arrays
    std::swap(A[(high + low) / 2], A[high]);

    int pivot = A[high];
    int i = low;
    int j = high - 1;

    while (true) {
        while (i <= high && A[i] < pivot) {
            i++;
        }

        while (j >= low && A[j] >= pivot) {
            j--;
        }

        if (i <= j)
            std::swap(A[i], A[j]);
        else
            break;
    }

    std::swap(A[i], A[high]);
    return i;
}

void SortFunctions::QuickSort(std::vector<int>& A, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = QSPartition(A, low, high);

        QuickSort(A, low, pivotIndex - 1);
        QuickSort(A, pivotIndex + 1, high);
    }
}