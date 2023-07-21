//
//  InsertionSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

// Checked
//  https://youtu.be/IWT-Uoz_Sb8
void InsertionSort(int a[], int n)
{
    // Loop start from the second element of the array
    for (int i = 1; i < n; i++)
    {
        // Pick up the current element of the array
        int position = i;
        int curVal = a[i];
        // Loop backward until we found the element that smaller than the curVal
        // Each time there's an element larger than the curVal, we move that element forward 1 position in the array.
        while (position > 0 && curVal < a[position - 1])
        {
            a[position] = a[position - 1];
            position--;
        }
        // Finally, we assign curVal to the last position found.
        a[position] = curVal;
    }
}

void InsertionSortCountComp(int a[], int n, int &countCompare)
{
    // Loop start from the second element of the array
    for (int i = 1; ++countCompare && i < n; i++)
    {
        // Pick up the current element of the array
        int position = i;
        int curVal = a[i];
        // Loop backward until we found the element that smaller than the curVal
        // Each time there's an element larger than the curVal, we move that element forward 1 position in the array.
        while (++countCompare && position >= 0 && ++countCompare && curVal < a[position - 1])
        {
            a[position] = a[position - 1];
            position--;
        }
        // Finally, we assign curVal to the last position found.
        a[position] = curVal;
    }
}

void BinaryInsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curVal = a[i];

        // Binary search
        int left = 1;
        int right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (curVal < a[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        // Shift elements forward
        for (int j = i - 1; j >= left; j--)
        {
            a[j + 1] = a[j];
        }

        // Finally, we assign curVal to the last position found.
        a[left] = curVal;
    }
}

void BinaryInsertionSort(int a[], int n, int &countCompare)
{
    for (int i = 1; ++countCompare && i < n; i++)
    {
        int curVal = a[i];

        // Binary search
        int left = 1;
        int right = i - 1;
        while (++countCompare && left <= right)
        {
            int mid = (left + right) >> 1;
            if (++countCompare && curVal < a[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        // Shift elements forward
        for (int j = i - 1; ++countCompare && j >= left; j--)
        {
            a[j + 1] = a[j];
        }

        // Finally, we assign curVal to the last position found.
        a[left] = curVal;
    }
}