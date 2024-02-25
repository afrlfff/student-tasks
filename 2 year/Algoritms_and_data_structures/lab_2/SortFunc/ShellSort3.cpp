#include <iostream>
#include <vector>
#include "SortFunctions.h"

void SortFunctions::ShellSort3(std::vector<int>& A, int low, int high)
{
	const int SIZE = 9;
	int steps[SIZE] = { 1, 4, 10, 23, 57, 132, 301, 701, 1750 };
	int ind = -1, d;
	for (int i = 0; (ind + 1) < SIZE; ind++)
	{
		if (steps[ind + 1] > (high - low + 1))
			break;
	}

	while (ind > 0)
	{
		d = steps[ind];
		for (int i = low; i <= (high - d); i++)
		{
			if (A[i] > A[i + d])
			{
				std::swap(A[i], A[i + d]);
			}
		}
		ind--;
	}
	InsertionSort(A, low, high);
}