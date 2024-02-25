#include <iostream>
#include <vector>
#include "SortFunctions.h"

void Heapify(std::vector<int>& A, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && A[left] > A[largest])
        largest = left;
    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        std::swap(A[largest], A[i]);
        Heapify(A, n, largest);
    }
}

void SortFunctions::HeapSort(std::vector<int>& A, int low, int high)
{
    if (low >= high)
        return;
    int size = (high - low + 1);
    // ����������� ������������� �������� � ������ ����
    for (int i = (high + 1) / 2 - 1; i >= low; i--)
    {
        Heapify(A, size, i);
    }

    // ���� �� ������ ��������� �������� �� ����
    for (int i = high; i >= low; i--)
    {
        // ���������� ������� ������ � �����
        std::swap(A[0], A[i]);

        // �������� ��������� heapify �� ����������� ����
        Heapify(A, i, 0);
    }
}