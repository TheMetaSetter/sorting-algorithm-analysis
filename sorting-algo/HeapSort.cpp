//
//  HeapSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

// Checked
//  Function to heapify the tree
void Heapify(int a[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && a[left] > a[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && a[right] > a[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(a[i], a[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(a, n, largest);
    }
}

// Main function to do heap sort
void HeapSort(int a[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(a[0], a[i]);

        // call max heapify on the reduced heap
        Heapify(a, i, 0);
    }
}

// Heapify function with comparison count
void HeapifyCount(int a[], int n, int i, int &countCompare)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++countCompare && left < n)
    {
        if (a[left] > a[largest])
            largest = left;
    }

    if (++countCompare && right < n)
    {
        if (a[right] > a[largest])
            largest = right;
    }

    if (++countCompare && largest != i)
    {
        swap(a[i], a[largest]);

        HeapifyCount(a, n, largest, countCompare);
    }
}

// HeapSort function with comparison count
void HeapSortCountComp(int a[], int n, int &countCompare)
{
    for (int i = n / 2 - 1; ++countCompare && i >= 0; i--)
        HeapifyCount(a, n, i, countCompare);

    for (int i = n - 1; ++countCompare && i >= 0; i--)
    {
        swap(a[0], a[i]);

        HeapifyCount(a, i, 0, countCompare);
    }
}
