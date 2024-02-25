#include <iostream>
#include <vector>
#include "SortFunctions.h"

void SortFunctions::InsertionSort(std::vector<int>& A, int low, int high)
{
	for (int i = low + 1; i <= high; i++)
	{
		for (int j = i; j > low; j--)
		{
			if (A[j] < A[j - 1])
			{
				std::swap(A[j], A[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}