#include <iostream>
#include <vector>
#include "SortFunctions.h"

const int INSERTION_THRESHOLD = 16;

// Функция для выбора опорного элемента
int choosePivot(std::vector<int>& A, int low, int high) {
    int mid = (low + high) / 2;

    if (A[low] > A[high]) {
        std::swap(A[low], A[high]);
    }
    if (A[low] > A[mid]) {
        std::swap(A[low], A[mid]);
    }
    if (A[mid] > A[high]) {
        std::swap(A[mid], A[high]);
    }

    std::swap(A[mid], A[high - 1]);
    return high - 1;
}

// Функция для разделения массива и выполнения сортировки "Хоара"
int ISpartition(std::vector<int>& A, int low, int high) {
    int pivotIndex = choosePivot(A, low, high);
    int pivot = A[pivotIndex];

    int i = low;
    int j = high - 1;

    while (true) {
        while (A[++i] < pivot) {}
        while (A[--j] > pivot) {}
        if (i < j) {
            std::swap(A[i], A[j]);
        }
        else {
            break;
        }
    }

    std::swap(A[i], A[high - 1]);
    return i;
}

// Функция для выполнения сортировки IntroSort
void introSort(std::vector<int>& A, int low, int high, int depthLimit) {
    while (high - low > INSERTION_THRESHOLD) {
        if (depthLimit == 0) {
            SortFunctions::HeapSort(A, low, high);
            return;
        }
        depthLimit--;

        int pivotIndex = ISpartition(A, low, high);
        introSort(A, pivotIndex + 1, high, depthLimit);

        high = pivotIndex;
    }

    SortFunctions::InsertionSort(A, low, high);
}

// Функция для вызова IntroSort
void SortFunctions::IntroSort(std::vector<int>& A, int low, int high) {
    int depthLimit = 2 * log(high - low + 1);
    introSort(A, 0, high - low, depthLimit);
}