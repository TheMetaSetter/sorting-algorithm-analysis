//
//  ShakerSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"
// ShakerSort function
void ShakerSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration
        swapped = false;

        // loop from left to right same as the bubble sort
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it can be used in the next stage
        swapped = false;

        // move the end point back by one, because item at the end is in its rightful spot
        --end;

        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // increase the start point, because the last stage would have moved the next smallest number to its rightful spot.
        ++start;
    }
}

// ShakerSort function with comparison count
void ShakerSortCount(int arr[], int n, int &countCompare) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            countCompare++;  // Increment countCompare
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            countCompare++;  // Increment countCompare
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}


