#include <iostream>
#include <vector>

void OutArray(std::vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';
}