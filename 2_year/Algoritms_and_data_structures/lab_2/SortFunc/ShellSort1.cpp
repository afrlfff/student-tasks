#include <iostream>
#include <vector>
#include "SortFunctions.h"

void SortFunctions::ShellSort1(std::vector<int>& A, int low, int high)
{
	int size = (high - low + 1);
	int d = size / 2;
	while (d > 0)
	{
		for (int i = low; i <= (high - d); i++)
		{
			if (A[i] > A[i + d])
			{
				std::swap(A[i], A[i+d]);
			}
		}
		d /= 2;
	}
	InsertionSort(A, low, high);
}