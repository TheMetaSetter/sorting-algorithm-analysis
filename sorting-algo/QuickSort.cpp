//
//  QuickSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}



// Hàm Partition giúp sắp xếp mảng và trả về chỉ mục pivot, đồng thời cập nhật số lần so sánh.
int PartitionWithCount(int arr[], int low, int high, int &countCompare) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        // Cộng thêm 1 lần so sánh khi tiến hành so sánh các phần tử.
        countCompare++;

        if (arr[j] < pivot) {
            i++;
            Swap(arr[i], arr[j]);
        }
    }

    Swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm QuickSort chính với tham số tham chiếu countCompare
void QuickSortCountComp(int arr[], int low, int high, int &countCompare) {
    if (low < high) {
        int pivot = PartitionWithCount(arr, low, high, countCompare);

        QuickSortCountComp(arr, low, pivot - 1, countCompare);
        QuickSortCountComp(arr, pivot + 1, high, countCompare);
    }
}

