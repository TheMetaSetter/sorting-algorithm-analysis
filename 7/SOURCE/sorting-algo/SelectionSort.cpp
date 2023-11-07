//
//  SelectionSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

//  Selection Sort
void SelectionSort(int a[], int n)
{
    int lastPos = n - 1; // The last position of the array
    // For each position of the array, we find the element that will fit into that position - the element's final position.
    for (int i = 0; i < lastPos; i++)
    {
        int minIdx = i;    // The index of the minimum element in the sub-array starting from index i + 1
        int minVal = a[i]; // The value of the minimum element starting from index i + 1
        // At each iteration, find the minimum element in the array starting from index i + 1.
        for (int j = i + 1; j <= lastPos; j++)
        {
            if (a[j] < minVal)
            {
                minIdx = j;
                minVal = a[j];
            }
        }
        // Swap the minimum element and the element at position i
        a[minIdx] = a[i];
        a[i] = minVal;
    }
}

void SelectionSortCountComp(int a[], int n, ull &countCompare)
{
    int lastPos = n - 1; // The last position of the array
    // For each position of the array, we find the element that will fit into that position - the element's final position.
    for (int i = 0; ++countCompare && i < lastPos; i++)
    {
        int minIdx = i;    // The index of the minimum element in the sub-array starting from index i + 1
        int minVal = a[i]; // The value of the minimum element starting from index i + 1
        // At each iteration, find the minimum element in the array starting from index i + 1.
        for (int j = i + 1; ++countCompare && j <= lastPos; j++)
        {
            if (++countCompare && a[j] < minVal)
            {
                minIdx = j;
                minVal = a[j];
            }
        }
        // Swap the minimum element and the element at position i
        a[minIdx] = a[i];
        a[i] = minVal;
    }
}
