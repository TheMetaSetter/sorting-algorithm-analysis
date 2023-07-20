//
//  SortingAlgorithms.hpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#ifndef SortingAlgorithms_hpp
#define SortingAlgorithms_hpp

#define DECLARE_ALGO(n) \
    void n (int a[], int n); \
    void n ## CountComp(int a[], int n, int &count);

#include <iostream>

using namespace std;

DECLARE_ALGO(InsertionSort)
DECLARE_ALGO(ShellSort)
DECLARE_ALGO(CountingSort)
DECLARE_ALGO(FlashSort)
DECLARE_ALGO(RadixSort)

#endif /* SortingAlgorithms_hpp */
