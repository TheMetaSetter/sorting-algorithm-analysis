//
//  QuickSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

// Checked
//  Quick Sort
int Partition(int a[], int left, int right)
{
    int pivot = a[left];
    int i = left;
    int j = right + 1;

    do
    {
        do
            i++;
        while (i <= right && a[i] < pivot);
        do
            j--;
        while (j >= left && a[j] > pivot);

        swap(a[i], a[j]);
    } while (i < j);

    swap(a[i], a[j]);

    swap(a[left], a[j]);

    return j;
}

void QuickSortCore(int a[], int left, int right)
{
    if (left < right)
    {
        int pivotIdx = Partition(a, left, right); // Divide the array into 3 parts: left part, a pivot and right part
        QuickSortCore(a, left, pivotIdx - 1);     // Sort left part
        QuickSortCore(a, pivotIdx + 1, right);    // Sort right part
    }
}

void QuickSort(int a[], int n)
{
    QuickSortCore(a, 0, n - 1);
}

int PartitionCountComp(int a[], int left, int right, int &countCompare)
{
    int pivot = a[left];
    int i = left;
    int j = right + 1;

    do
    {
        do
        {
            i++;
        } while (++countCompare && i <= right && ++countCompare && a[i] < pivot);
        do
        {
            j--;
        } while (++countCompare && j >= left && ++countCompare && a[j] > pivot);

        swap(a[i], a[j]);
    } while (++countCompare && i < j);

    swap(a[i], a[j]);

    swap(a[left], a[j]);

    return j;
}

void QuickSortCountCompCore(int a[], int left, int right, int &countCompare)
{
    if (++countCompare && left < right)
    {
        int pivotIdx = PartitionCountComp(a, left, right, countCompare); // Divide the array into 3 parts: left part, a pivot and right part
        QuickSortCountCompCore(a, left, pivotIdx - 1, countCompare);
        QuickSortCountCompCore(a, pivotIdx + 1, right, countCompare);
    }
}

void QuickSortCountComp(int a[], int n, int &countCompare)
{
    QuickSortCountCompCore(a, 0, n - 1, countCompare);
}
