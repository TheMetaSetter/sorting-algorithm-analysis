//
//  BubbleSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

void BubbleSort(int arr[], int n)
{
    /*
     After passing through n - 1 elements, those n - 1 elements have already been placed in their correct positions (pushed to the end of the array), and since the array only has n elements, the remaining element is certainly in its correct position.
     */
    for (int i = 0; i < n - 1; i++)
    {
        /*
         After going through n - 1 elements, there is only one pair of elements left to be considered, which are arr[n - 2] and arr[n - 1].
         */
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void BubbleSortCountComp(int arr[], int n, ull &countCompare)
{
    /*
     After passing through n - 1 elements, those n - 1 elements have already been placed in their correct positions (pushed to the end of the array), and since the array only has n elements, the remaining element is certainly in its correct position.
     */
    for (int i = 0; ++countCompare && i < n - 1; i++)
    {
        /*
         After going through n - 1 elements, there is only one pair of elements left to be considered, which are arr[n - 2] and arr[n - 1].
         */
        for (int j = 0; ++countCompare && j < n - 1; j++)
        {
            if (++countCompare && arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*
 The 3 weaknesses of bubble sort is:
 1. It is inefficient for large arrays. The time complexity of bubble sort is O(n^2), which means that the algorithm takes a quadratic number of comparisons to sort an array of n elements. This makes it inefficient for large arrays, as the number of comparisons grows very quickly with the size of the array.
 2. It does not take advantage of already sorted data. If the array is already sorted, bubble sort will still run through all of the comparisons, even though the array is already in the correct order. This means that bubble sort can be inefficient if the array is already sorted.
 3. It is not a stable sort. A stable sort is a sort that preserves the relative order of equal elements in the array. For example, if the array contains the elements [1, 1, 2, 3], then a stable sort would preserve the order of the 1s, so the sorted array would be [1, 1, 2, 3]. Bubble sort is not a stable sort, so it is possible for the relative order of equal elements to be changed during the sorting process.

 These weaknesses lead to 3 ways that we can use to improve the bubble sort algorithm.
 1. Remembering whether or not any exchange had taken place during a pass. This is known as the break condition. If no exchanges take place during a pass, then the array is already sorted, so the algorithm can terminate early. This can improve the performance of the algorithm, especially if the array is already sorted.
 2. Remembering the position of the last change. This is known as the optimised bubble sort. The algorithm starts comparing elements from the position of the last change and continues until it reaches the end of the array. This can significantly reduce the number of comparisons that need to be made, which can improve the performance of the algorithm.
 3. Alternating the direction of consecutive passes. This is known as the cocktail shaker sort. The algorithm starts by comparing elements from left to right, and then it compares elements from right to left. This can help to ensure that the array is sorted more quickly.
 */

void OptimisedBubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}

void OptimisedBubbleSortCountComp(int arr[], int n, ull &countCompare)
{
    for (int i = 0; ++countCompare && i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; ++countCompare && j < n - 1; j++)
        {
            if (++countCompare && arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (++countCompare && !swapped)
        {
            return;
        }
    }
}