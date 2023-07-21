// https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp

#include "sorting-algo/SortingAlgorithms.hpp"
#include "helper/Helper.hpp"
#include <chrono>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <fstream>
#include <cstring>

// Library to measure running time of a function
using namespace std::chrono;

std::unordered_map<std::string, std::function<void(int *, int)>>
    algorithms = {
        {"bubble-sort", BubbleSort},
        {"counting-sort", CountingSort},
        {"flash-sort", FlashSort},
        {"heap-sort", HeapSort},
        {"insertion-sort", InsertionSort},
        {"merge-sort", MergeSort},
        {"quick-sort", QuickSort},
        {"radix-sort", RadixSort},
        {"selection-sort", SelectionSort},
        {"shaker-sort", ShakerSort},
        {"ShellSort", ShellSort}};

std::unordered_map<std::string, std::function<void(int *, int, int &)>>
    algorithmsCount = {
        {"bubble-sort", BubbleSortCountComp},
        {"counting-sort", CountingSortCountComp},
        {"flash-sort", FlashSortCountComp},
        {"heap-sort", HeapSortCountComp},
        {"insertion-sort", InsertionSortCountComp},
        {"merge-sort", MergeSortCountComp},
        {"quick-sort", QuickSortCountComp},
        {"radix-sort", RadixSortCountComp},
        {"selection-sort", SelectionSortCountComp},
        {"shaker-sort", ShakerSortCountComp},
        {"ShellSort", ShellSortCountComp}};

std::unordered_map<std::string, int>
    dataOrder = {
        {"-rand", 0},
        {"sorted", 1},
        {"rev", 2},
        {"-nsorted", 3}
};

int main(int argc, const char *argv[])
{

    if (strcmp(argv[1], "-a") == 0)
    {
        // Print title
        cout << "ALGORITHM MODE" << endl;

        // Get the algorithm name
        std::string algoName = argv[2];

        // Print algorithm name
        cout << "Algorithm: " << algoName << endl;

        // Algorithm mode
        if (argc == 5)
        {
            if (auto algo = algorithms.find(algoName); algo != algorithms.end())
            {
                // The 'atoi' function return 0 if the cstring cannot be converted to integer.
                int checkChar = atoi(argv[3]);
                // Command 1 and 3
                if (checkChar == 0)
                {
                    // Print input-data file-name
                    cout << "Input file: " << argv[3] << endl;

                    // Input data
                    int size;
                    int *a;
                    InputArrayFromTxtFile(a, size, argv[3]);

                    // Print size of input data
                    cout << "Input size: " << size << endl;

                    // Mesure running time
                    auto start = steady_clock::now();
                    algo->second(a, size);
                    auto end = steady_clock::now();
                    int runningTime = duration_cast<microseconds>(end - start).count(); // in microseconds (μs)

                    // Count comparison
                    int countCompare = 0;
                    algorithmsCount[algoName](a, size, countCompare);

                    // Print result
                    bool printRunTime = false;
                    bool printCountCompare = false;
                    printRunTime = strcmp(argv[4], "-time") ? true : false;
                    printCountCompare = strcmp(argv[4], "-comp") ? true : false;
                    if (strcmp(argv[4], "-both"))
                    {
                        printRunTime = true;
                        printCountCompare = true;
                    }

                    if (printRunTime)
                    {
                        cout << "Running time (if required): " << runningTime << " μs\n";
                    }
                    if (printCountCompare)
                    {
                        cout << "Comparisons (if required): " << countCompare << " comparisons\n";
                    }
                }
                // Command 2
                // If the argv[3] is not char, then it is integer.
                else
                {
                    int size = checkChar;

                    //Print input size
                    cout << "Input size: " << argv[3] << endl;

                    for (auto order: dataOrder) {
                        
                    } 
                }
            }
            else
            {
                std::cout << "Algorithm not found!\n";
            }
        }
        else if (argc == 6)
        {
            if (auto algo = algorithms.find(algoName); algo != algorithms.end())
            {
            }
            else
            {
                std::cout << "Algorithm not found!\n";
            }
        }
        else
        {
            cout << "Error: Invalid number of arguments." << endl;
        }
    }

    return 0;
}
