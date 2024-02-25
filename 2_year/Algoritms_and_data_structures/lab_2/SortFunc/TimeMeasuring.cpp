//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <chrono>
//#include <fstream>
//
//#include "constants.h"
//#include "CallSort.h"
//
//// if this method not commented, so the Main() method
//// in file Program.cpp should be commmented
//int main()
//{
//	int startNumber;
//	srand(time(0));
//	std::fstream file;
//
//
//	// ========== Making Sorted Array ========== //
//
//	startNumber = 5;
//	std::vector<int> SortedArray = { startNumber };
//	for (int i = 0; i < ARRAY_SIZE - 1; i++)
//		SortedArray.push_back(SortedArray[i] + ((rand() * RAND_COEFFICIENT) % 100));
//
//
//	// ========== Making BackSorted Array ========== //
//
//	startNumber = 100005;
//	std::vector<int> BackSortedArray = { startNumber };
//	for (int i = 0; i < ARRAY_SIZE - 1; i++)
//			BackSortedArray.push_back(BackSortedArray[i] - ((rand() * RAND_COEFFICIENT) % 100));
//
//
//	// ========== Making Almost Sorted Array ========== //
//
//	// step between elements which will be backsorted in already sorted array
//	// I made it to be 5%
//	int stepTmp = ARRAY_SIZE / (ARRAY_SIZE * 0.05);
//
//	std::vector<int> AlmostSortedArray = SortedArray;
//	for (int i = 0; i < ARRAY_SIZE; i += stepTmp)
//		std::swap(AlmostSortedArray[i], AlmostSortedArray[i + 1]);
//
//
//	// ========== Making Random Array ========== //
//
//	std::vector<int> RandomArray = { startNumber };
//	for (int i = 0; i < ARRAY_SIZE - 1; i++)
//		RandomArray.push_back((rand() * RAND_COEFFICIENT) % 10000);
//
//
//	// ========== Making AllArrays ========== //
//
//	std::vector<std::vector<int>*> AllArrays {
//		&SortedArray,
//		&BackSortedArray,
//		&AlmostSortedArray,
//		&RandomArray
//	};
//
//
//	// ==========
//	// ========== Time measuring ========== //
//	// ==========
//
//	std::vector<int>* CurrentArray;
//	std::vector<int> CurrentArrayCopy;
//	int repeat;
//	double minTime;
//
//	for (int i = FILE_PATHS_START_INDEX; i < (FILE_PATHS_END_INDEX + 1); i++)
//	{
//		for(int j = 0; j < AllArrays.size(); j++)
//		{
//			if (j != 3)
//				continue;
//			CurrentArray = AllArrays[j];
//			file.open(FILE_PATHS[j][i], std::ios::out);
//			std::cout << FILE_PATHS[j][i] << std::endl;
//
//			for (int k = 1; k <= ARRAY_SIZE; k += (SIZE_STEP - (k == 1)))
//			{
//				// установка повторов для алгоритма QuickSort
//				if (k < 10000)
//					repeat = 100;
//				else if (k >= 10000 && k < 20000)
//					repeat = 50;
//				else if (k >= 20000 && k < 35000)
//					repeat = 25;
//				else
//					repeat = 25;
//
//				minTime = 100000;
//				for (int l = 0; l < repeat; l++)
//				{
//					copy(CurrentArray->begin(), CurrentArray->begin() + k, back_inserter(CurrentArrayCopy));
//					auto start_time = std::chrono::steady_clock::now();
//					CallSort(CurrentArrayCopy, i+1);
//					auto end_time = std::chrono::steady_clock::now();
//					std::chrono::duration<double> elapsed_seconds = end_time - start_time;
//
//					if (elapsed_seconds.count() < minTime)
//						minTime = elapsed_seconds.count();
//
//					CurrentArrayCopy.clear();
//				}
//
//				file << std::fixed << std::setprecision(8) << minTime << '\n';
//
//				std::cout << "current size: " << k << std::endl;
//			}
//			file.close();
//			std::cout << (i+1) << ") Done." << std::endl;
//		}
//	}
//}