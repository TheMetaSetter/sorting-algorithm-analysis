//https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp

#include "sorting-algo/SortingAlgorithms.hpp"
#include "helper/Helper.hpp"

int main() {

    //Test FlashSort
    int a[10];
    GenerateData(a, 10, 0);

    FlashSort(a, 10);

    // int countCompare = 0;
    // FlashSortCountComp(a, 10, countCompare);

    PrintArray(a, 10);

    return 0;
}
