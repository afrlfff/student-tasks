#pragma once
#include <iostream>
#include <vector>

class SortFunctions
{
public:
	static void SelectionSort(std::vector<int>& A, int low, int high);
	static void InsertionSort(std::vector<int>& A, int low, int high);
	static void BubbleSort(std::vector<int>& A, int low, int high);
	static void MergeSort(std::vector<int>& A, int low, int high);
	static void QuickSort(std::vector<int>& A, int low, int high);
	static void ShellSort1(std::vector<int>& A, int low, int high);
	static void ShellSort2(std::vector<int>& A, int low, int high);
	static void ShellSort3(std::vector<int>& A, int low, int high);
	static void HeapSort(std::vector<int>& A, int low, int high);
	static void TimSort(std::vector<int>& A, int low, int high);
	static void IntroSort(std::vector<int>& A, int low, int high);
};