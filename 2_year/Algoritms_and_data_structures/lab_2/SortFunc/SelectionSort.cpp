#include <iostream>
#include <vector>
#include "SortFunctions.h"

void SortFunctions::SelectionSort(std::vector<int>& A, int low, int high)
{
	int maxInd;

	for (int i = low; i <= high; i++)
	{
		maxInd = low;
		for (int j = low + 1; j <= (high - i); j++)
		{
			if (A[j] > A[maxInd])
				maxInd = j;
		}
		std::swap(A[maxInd], A[high - i]);
	}
}