//
//  CountingSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

// https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp
#include "SortingAlgorithms.hpp"

// Checked
void CountingSort(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	int *count = new int[max + 1];
	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	int *temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = temp[i];
	delete[] count;
	delete[] temp;
}

void CountingSortCountComp(int a[], int n, int &countCompare)
{
	int max = a[0];
	for (int i = 1; ++countCompare && i < n; i++)
		if (++countCompare && a[i] > max)
			max = a[i];

	int *count = new int[max + 1];
	for (int i = 0; ++countCompare && i <= max; i++)
		count[i] = 0;

	for (int i = 0; ++countCompare && i < n; i++)
		count[a[i]]++;

	for (int i = 1; ++countCompare && i <= max; i++)
		count[i] += count[i - 1];

	int *temp = new int[n];
	for (int i = 0; ++countCompare && i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; ++countCompare && i < n; i++)
		a[i] = temp[i];

	delete[] count;
	delete[] temp;
}