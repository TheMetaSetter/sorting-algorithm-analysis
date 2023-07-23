//
//  QuickSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

int Partition(int a[], int left, int right)
{
    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;
    int tmp;
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp; //
            i++;
            j--;
        }
    }
    return i;
}

void QuickSortCore(int a[], int left, int right)
{
    int index = Partition(a, left, right);
    if (left < index - 1)
        QuickSortCore(a, left, index - 1);
    if (index < right)
        QuickSortCore(a, index, right);
}

void QuickSort(int a[], int n)
{
    QuickSortCore(a, 0, n - 1);
}

int PartitionCountComp(int a[], int left, int right, ull &countCompare)
{
    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;
    int tmp;
    while (++countCompare && i <= j)
    {
        while (++countCompare && a[i] < pivot)
            i++;
        while (++countCompare && a[j] > pivot)
            j--;
        if (++countCompare && i <= j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

void QuickSortCountCompCore(int a[], int left, int right, ull &countCompare)
{
    int index = PartitionCountComp(a, left, right, countCompare);
    if (++countCompare && left < index - 1)
        QuickSortCountCompCore(a, left, index - 1, countCompare);
    if (++countCompare && index < right)
        QuickSortCountCompCore(a, index, right, countCompare);
}

void QuickSortCountComp(int a[], int n, ull &countCompare)
{
    QuickSortCountCompCore(a, 0, n - 1, countCompare);
}