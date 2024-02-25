#pragma once

#include <iostream>
#include <vector>

// ==========
// ========== Constants For Time Measuring ========== //
// ==========

// max size of array
const uint16_t ARRAY_SIZE = 50000;

// difference between each size to sort
constexpr uint16_t SIZE_STEP = ARRAY_SIZE / 50;

// coefficient to generate all int numbers by rand() function 
constexpr uint16_t RAND_COEFFICIENT = 2147483648 / RAND_MAX;

// paths to result files
const std::string FILE_PATHS[4][11] = {
	{
		"..\\results_txt\\SortedArray\\SelectionSort.txt",
		"..\\results_txt\\SortedArray\\InsertionSort.txt",
		"..\\results_txt\\SortedArray\\BubbleSort.txt",
		"..\\results_txt\\SortedArray\\MergeSort.txt",
		"..\\results_txt\\SortedArray\\QuickSort.txt",
		"..\\results_txt\\SortedArray\\ShellSort1.txt",
		"..\\results_txt\\SortedArray\\ShellSort2.txt",
		"..\\results_txt\\SortedArray\\ShellSort3.txt",
		"..\\results_txt\\SortedArray\\HeapSort.txt",
		"..\\results_txt\\SortedArray\\TimSort.txt",
		"..\\results_txt\\SortedArray\\IntroSort.txt"
	},
	{
		"..\\results_txt\\BackSortedArray\\SelectionSort.txt",
		"..\\results_txt\\BackSortedArray\\InsertionSort.txt",
		"..\\results_txt\\BackSortedArray\\BubbleSort.txt",
		"..\\results_txt\\BackSortedArray\\MergeSort.txt",
		"..\\results_txt\\BackSortedArray\\QuickSort.txt",
		"..\\results_txt\\BackSortedArray\\ShellSort1.txt",
		"..\\results_txt\\BackSortedArray\\ShellSort2.txt",
		"..\\results_txt\\BackSortedArray\\ShellSort3.txt",
		"..\\results_txt\\BackSortedArray\\HeapSort.txt",
		"..\\results_txt\\BackSortedArray\\TimSort.txt",
		"..\\results_txt\\BackSortedArray\\IntroSort.txt"
	},
	{
		"..\\results_txt\\AlmostSortedArray\\SelectionSort.txt",
		"..\\results_txt\\AlmostSortedArray\\InsertionSort.txt",
		"..\\results_txt\\AlmostSortedArray\\BubbleSort.txt",
		"..\\results_txt\\AlmostSortedArray\\MergeSort.txt",
		"..\\results_txt\\AlmostSortedArray\\QuickSort.txt",
		"..\\results_txt\\AlmostSortedArray\\ShellSort1.txt",
		"..\\results_txt\\AlmostSortedArray\\ShellSort2.txt",
		"..\\results_txt\\AlmostSortedArray\\ShellSort3.txt",
		"..\\results_txt\\AlmostSortedArray\\HeapSort.txt",
		"..\\results_txt\\AlmostSortedArray\\TimSort.txt",
		"..\\results_txt\\AlmostSortedArray\\IntroSort.txt"
	},
	{
		"..\\results_txt\\RandomArray\\SelectionSort.txt",
		"..\\results_txt\\RandomArray\\InsertionSort.txt",
		"..\\results_txt\\RandomArray\\BubbleSort.txt",
		"..\\results_txt\\RandomArray\\MergeSort.txt",
		"..\\results_txt\\RandomArray\\QuickSort.txt",
		"..\\results_txt\\RandomArray\\ShellSort1.txt",
		"..\\results_txt\\RandomArray\\ShellSort2.txt",
		"..\\results_txt\\RandomArray\\ShellSort3.txt",
		"..\\results_txt\\RandomArray\\HeapSort.txt",
		"..\\results_txt\\RandomArray\\TimSort.txt",
		"..\\results_txt\\RandomArray\\IntroSort.txt"
	}
};

// index from which to start check filePaths (from 0 to 10)
const uint8_t FILE_PATHS_START_INDEX = 4;

// index from which to end check filePaths (from 0 to 10)
const uint8_t FILE_PATHS_END_INDEX = 4;

// both indexes are 4, it means that only QuickSort will be checked