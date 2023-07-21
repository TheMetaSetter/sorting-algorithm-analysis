//
//  SortingAlgorithms.hpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#ifndef SortingAlgorithms_hpp
#define SortingAlgorithms_hpp

#define DECLARE_ALGO(n)     \
    void n(int a[], int n); \
    void n##CountComp(int a[], int n, int &countCompare);

#include <iostream>

using namespace std;

DECLARE_ALGO(BubbleSort)
DECLARE_ALGO(CountingSort)
DECLARE_ALGO(FlashSort)
DECLARE_ALGO(HeapSort)
DECLARE_ALGO(InsertionSort)
DECLARE_ALGO(MergeSort)
DECLARE_ALGO(QuickSort)
DECLARE_ALGO(RadixSort)
DECLARE_ALGO(SelectionSort)
DECLARE_ALGO(ShakerSort)
DECLARE_ALGO(ShellSort)

#endif /* SortingAlgorithms_hpp */
