//
//  HeapSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"
// Function to heapify the tree
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Heapify function with comparison count
void heapifyCount(int arr[], int n, int i, int &countCompare) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        countCompare++;  // Increment countCompare
        if (arr[left] > arr[largest])
            largest = left;
    }

    if (right < n) {
        countCompare++;  // Increment countCompare
        if (arr[right] > arr[largest])
            largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapifyCount(arr, n, largest, countCompare);
    }
}

// HeapSort function with comparison count
void heapSortCount(int arr[], int n, int &countCompare) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyCount(arr, n, i, countCompare);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

        heapifyCount(arr, i, 0, countCompare);
    }
}
