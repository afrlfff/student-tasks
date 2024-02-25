#include <iostream>
#include <vector>
#include "SortFunctions.h"

void SortFunctions::BubbleSort(std::vector<int>& A, int low, int high)
{
	for (int i = low; i <= high; i++)
	{
		for (int j = low; j < (high - i); j++)
		{
			if (A[j] > A[j + 1])
			{
				std::swap(A[j], A[j+1]);
			}
		}
	}
}