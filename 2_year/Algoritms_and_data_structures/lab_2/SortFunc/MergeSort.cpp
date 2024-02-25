#include <iostream>
#include <vector>
#include "SortFunctions.h"

void MSMerge(std::vector<int>& A,int low, int mid, int high)
{
    int indA1 = low, indA2 = mid + 1, indR = 0;
    int resultLength = high - low + 1;
    std::vector<int> result(resultLength);

    while (indA1 < (mid + 1) && indA2 < (high + 1))
    {
        if (A[indA1] > A[indA2])
        {
            result[indR] = A[indA2];
            indA2++;
        }
        else
        {
            result[indR] = A[indA1];
            indA1++;
        }
        indR++;
    }
    if (indA1 == (mid + 1))
    {
        while (indR < resultLength)
        {
            result[indR] = A[indA2];
            indA2++; indR++;
        }
    }
    else // if (indA2 == high+1)
    {
        while (indR < resultLength)
        {
            result[indR] = A[indA1];
            indA1++; indR++;
        }
    }

    // ÏÐÅÎÁÐÀÇÓÅÌ ÈÑÕÎÄÍÛÉ ÌÀÑÑÈÂ, ÂÌÅÑÒÎ ÑÎÇÄÀÍÈß ÂÑÏÎÌÎÃÀÒÅËÜÍÛÕ
    for (int i = 0; i < resultLength; i++)
    {
        A[low + i] = result[i];
    }
}

void SortFunctions::MergeSort(std::vector<int>& A, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        
        MSMerge(A, low, mid, high);

        
    }
}