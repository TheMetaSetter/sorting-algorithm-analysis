//
//  FlashSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

//https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp
#include "SortingAlgorithms.hpp"

void FlashSort(int a[], int n) {
	int minVal = a[0];
	int maxVal = 0;
	int numOfBuckets = int(0.45 * n);
	int* bucketCounts = new int[numOfBuckets];
	for (int i = 0; i < numOfBuckets; i++)
		bucketCounts[i] = 0;
    
	for (int i = 1; i < n; i++) {
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[maxVal])
			maxVal = i;
	}

	if (a[maxVal] == minVal)
		return;
    
	double bucketWidth = (double)(numOfBuckets - 1) / (a[maxVal] - minVal);
	for (int i = 0; i < n; i++) {
		int bucketIdx = int(bucketWidth * (a[i] - minVal));
		++bucketCounts[bucketIdx];
	}

	for (int i = 1; i < numOfBuckets; i++)
		bucketCounts[i] += bucketCounts[i - 1];
    
    //Flash Sort Algorithm
	HoanVi(a[maxVal], a[0]);
	int numOfMoves = 0;
	int currElement = 0;
	int bucketIdx = numOfBuckets - 1;
	int temp = 0;
	int currVal;
	while (numOfMoves < n - 1) {
		while (currElement > bucketCounts[bucketIdx] - 1) {
			currElement++;
			bucketIdx = int(bucketWidth * (a[currElement] - minVal));
		}
		currVal = a[currElement];
		if (bucketIdx < 0) break;
		while (currElement != bucketCounts[bucketIdx]) {
			bucketIdx = int(bucketWidth * (currVal - minVal));
			int hold = a[temp = --bucketCounts[bucketIdx]];
			a[temp] = currVal;
			currVal = hold;
			++numOfMoves;
		}
	}

	delete[] bucketCounts;

	InsertionSort(a, n);
}

void FlashSortCountComp(int a[], int n, int &countCompare) {
	int minVal = a[0];
	int maxVal = 0;
	int numOfBuckets = int(0.45 * n);
	int* bucketCounts = new int[numOfBuckets];
	for (int i = 0; ++countCompare && i < numOfBuckets; i++)
		bucketCounts[i] = 0;
    
	for (int i = 1; ++countCompare && i < n; i++) {
		if (++countCompare && a[i] < minVal)
			minVal = a[i];
		if (++countCompare && a[i] > a[maxVal])
			maxVal = i;
	}

	if (a[maxVal] == minVal)
		return;
    
	double bucketWidth = (double)(numOfBuckets - 1) / (a[maxVal] - minVal);
	for (int i = 0; ++countCompare && i < n; i++) {
		int bucketIdx = int(bucketWidth * (a[i] - minVal));
		++bucketCounts[bucketIdx];
	}

	for (int i = 1; ++countCompare && i < numOfBuckets; i++)
		bucketCounts[i] += bucketCounts[i - 1];
    
    //Flash Sort Algorithm
	HoanVi(a[maxVal], a[0]);
	int numOfMoves = 0;
	int currElement = 0;
	int bucketIdx = numOfBuckets - 1;
	int temp = 0;
	int currVal;
	while (++countCompare && numOfMoves < n - 1) {
		while (++countCompare && currElement > bucketCounts[bucketIdx] - 1) {
			currElement++;
			bucketIdx = int(bucketWidth * (a[currElement] - minVal));
		}
		currVal = a[currElement];
		if (++countCompare && bucketIdx < 0) break;
		while (++countCompare && currElement != bucketCounts[bucketIdx]) {
			bucketIdx = int(bucketWidth * (currVal - minVal));
			int hold = a[temp = --bucketCounts[bucketIdx]];
			a[temp] = currVal;
			currVal = hold;
			++numOfMoves;
		}
	}

	delete[] bucketCounts;

	InsertionSort(a, n);
}