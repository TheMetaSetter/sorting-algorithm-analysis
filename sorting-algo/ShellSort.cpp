//
//  ShellSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

void ShellSort(int a[], int n)
{
    for (int interval = n / 2; interval >= 1; interval /= 2)
    {
        for (int i = interval; i < n; i++)
        {
            int curVal = a[i];
            int j = i;
            while (j >= interval && a[j - interval] > curVal)
            {
                a[j] = a[j - interval];
                j -= interval;
            }
            a[j] = curVal;
        }
    }
}

void ShellSortCountComp(int a[], int n, ull &countCompare)
{
    for (int interval = n / 2; ++countCompare && interval >= 1; interval /= 2)
    {
        for (int i = interval; ++countCompare && i < n; i++)
        {
            int curVal = a[i];
            int j = i;
            while ((++countCompare && j >= interval) && (++countCompare && a[j - interval] > curVal))
            {
                a[j] = a[j - interval];
                j -= interval;
            }
            a[j] = curVal;
        }
    }
}