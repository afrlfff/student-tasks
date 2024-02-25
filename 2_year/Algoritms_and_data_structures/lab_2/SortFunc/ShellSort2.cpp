#include <iostream>
#include <vector>
#include "SortFunctions.h"

void SortFunctions::ShellSort2(std::vector<int>& A, int low, int high)
{
	const int SIZE = 28;
	int steps[] = {
		1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001,
		36289, 64769, 146305, 260609, 587521, 1045505, 2354689,
		4188161, 9427969, 16764929, 37730305, 67084289, 150958081,
		268386305, 603906049, 1073643521
	};
	/*
		if (steps.size() % 2 == 0)
			d = 9 * pow(2, steps.size()) - 9 * pow(2, steps.size() / 2) + 1;
		else
			d = 8 * pow(2, steps.size()) - 6 * pow(2, (steps.size() + 1) / 2) + 1;
	*/
	int ind = -1, d;
	for (int i = 0; (ind+1) < SIZE; ind++)
	{
		if (steps[ind+1] > (high - low + 1))
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