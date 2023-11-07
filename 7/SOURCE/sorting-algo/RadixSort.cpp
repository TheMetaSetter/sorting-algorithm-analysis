//
//  RadixSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

void RadixSort(int a[], int n)
{
	int *b = new int[n];
	int m = a[0], exp = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (m / exp > 0)
	{
		int bucket[10] = {0};
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
	delete[] b;
}

void RadixSortCountComp(int a[], int n, ull &countCompare)
{
	int *b = new int[n];
	int m = a[0], exp = 1;

	for (int i = 0; ++countCompare && i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (++countCompare && m / exp > 0)
	{
		int bucket[10] = {0};
		for (int i = 0; ++countCompare && i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; ++countCompare && i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; ++countCompare && i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; ++countCompare && i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}

	delete[] b;
}