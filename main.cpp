// https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp

// Libraries initialized in other places
#include "sorting-algo/SortingAlgorithms.hpp"
#include "helper/Helper.hpp"

// Built-in libraries used in this source
#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <fstream>
#include <chrono>
#include <cstring>

// To use steady_clock
using namespace std::chrono;

std::unordered_map<std::string, std::function<void(int *, int)>>
    algorithms = {
        {"bubble-sort", BubbleSort},
        {"optimised-bubble-sort", OptimisedBubbleSort},
        {"counting-sort", CountingSort},
        {"flash-sort", FlashSort},
        {"heap-sort", HeapSort},
        {"insertion-sort", InsertionSort},
        {"binary-insertion-sort", BinaryInsertionSort},
        {"merge-sort", MergeSort},
        {"quick-sort", QuickSort},
        {"radix-sort", RadixSort},
        {"selection-sort", SelectionSort},
        {"shaker-sort", ShakerSort},
        {"shell-sort", ShellSort}};

std::unordered_map<std::string, std::function<void(int *, int, ull &)>>
    algorithmsCount = {
        {"bubble-sort", BubbleSortCountComp},
        {"optimised-bubble-sort", OptimisedBubbleSortCountComp},
        {"counting-sort", CountingSortCountComp},
        {"flash-sort", FlashSortCountComp},
        {"heap-sort", HeapSortCountComp},
        {"insertion-sort", InsertionSortCountComp},
        {"binary-insertion-sort", BinaryInsertionSortCountComp},
        {"merge-sort", MergeSortCountComp},
        {"quick-sort", QuickSortCountComp},
        {"radix-sort", RadixSortCountComp},
        {"selection-sort", SelectionSortCountComp},
        {"shaker-sort", ShakerSortCountComp},
        {"shell-sort", ShellSortCountComp}};

std::unordered_map<std::string, int>
    dataOrder = {
        {"-rand", 0},
        {"-sorted", 1},
        {"-rev", 2},
        {"-nsorted", 3}};

int main(int argc, const char *argv[])
{
    std::string outFileName = "output.txt";

    if (strcmp(argv[1], "-a") == 0)
    {
        // Print title
        std::cout << "ALGORITHM MODE" << endl;

        // Get the algorithm name
        std::string algoName = argv[2];

        // Print algorithm name
        std::cout << "Algorithm: " << algoName << endl;

        // Algorithm mode
        if (argc == 5)
        {
            if (auto algo = algorithms.find(algoName); algo != algorithms.end())
            {
                // The 'atoi' function return 0 if the cstring cannot be converted to integer.
                int checkChar = atoi(argv[3]);
                // Command 1
                if (checkChar == 0)
                {
                    // Print input-data file-name
                    std::cout << "Input file: " << argv[3] << endl;

                    // Input data
                    int size;
                    int *a;
                    InputArrayFromTxtFile(a, size, argv[3]);

                    // Print size of input data
                    std::cout << "Input size: " << size << endl;

                    std::cout << "-------------------------\n";

                    // Mesure running time
                    int runningTime = MeasureRunningTime(algo->second, a, size);

                    // Write sorted array to txt file
                    WriteArrayToTxtFile(a, size, outFileName.c_str());

                    // Count comparison
                    ull countCompare = 0;
                    algorithmsCount[algoName](a, size, countCompare);

                    // Print result
                    PrintResult(argv[4], runningTime, countCompare);

                    std::cout << "\n\n";

                    // Delete a
                    delete[] a;
                }
                // Command 3
                // If the argv[3] is not char, then it is integer.
                else
                {
                    // We have convert argv[3] to integer at the start of this if-else
                    int size = checkChar;

                    // Print input size
                    std::cout << "Input size: " << size << endl
                              << endl;

                    for (auto order : dataOrder)
                    {
                        // Get the order index
                        int orderIdx = order.second;

                        // Print the order name
                        PrintOrderName(orderIdx);

                        // Generate data
                        int *a = new int[size];
                        GenerateData(a, size, orderIdx);

                        // Write input data to text file
                        std::string textFileName = "input_";
                        textFileName += to_string(orderIdx + 1);
                        textFileName += ".txt";
                        WriteArrayToTxtFile(a, size, textFileName.c_str());

                        // Measure running time
                        int runningTime = MeasureRunningTime(algo->second, a, size);

                        // Count comparison
                        ull countCompare = 0;
                        algorithmsCount[algoName](a, size, countCompare);

                        // Print result
                        PrintResult(argv[4], runningTime, countCompare);

                        std::cout << "\n\n";
                    }
                }
            }
            else
            {
                std::cout << "Algorithm not found!\n";
            }
        }
        // Command 2
        else if (argc == 6)
        {
            if (auto algo = algorithms.find(algoName); algo != algorithms.end())
            {
                // We convert argv[3] to integer
                int size = atoi(argv[3]);

                // Print input size
                std::cout << "Input size: " << size << endl;

                // Get input order
                std::string order = argv[4];

                // Print input order
                PrintOrderName(dataOrder[order]);

                // Get order index
                int orderIdx = dataOrder[order];

                // Generate data
                int *a = new int[size];
                GenerateData(a, size, orderIdx);

                // Write input data to text file
                std::string textFileName = "input.txt";
                WriteArrayToTxtFile(a, size, textFileName.c_str());

                // Measure running time
                int runningTime = MeasureRunningTime(algo->second, a, size);

                // Write sorted array to txt file
                WriteArrayToTxtFile(a, size, outFileName.c_str());

                // Count comparison
                ull countCompare = 0;
                algorithmsCount[algoName](a, size, countCompare);

                // Print result
                PrintResult(argv[5], runningTime, countCompare);

                // // Write experimental results to .csv file
                // WriteExperimentalResultToCsvFile(algoName, orderIdx, size, runningTime, countCompare);

                std::cout << "\n\n";

                delete[] a;
            }
            else
            {
                std::cout << "Algorithm not found!\n";
            }
        }
        else
        {
            std::cout << "Error: Invalid number of arguments." << endl;
        }
    }
    // Comparison mode
    else if (strcmp(argv[1], "-c") == 0)
    {
        // Print title
        std::cout << "COMPARISON MODE" << endl;

        // Get the algorithms name
        std::string algoName1 = argv[2];
        std::string algoName2 = argv[3];

        // Print algorithms name
        std::cout << "Algorithm: " << algoName1 << " | " << algoName2 << endl;

        // Command 4
        if (argc == 5)
        {
            if (auto algo1 = algorithms.find(algoName1); algo1 != algorithms.end())
            {
                if (auto algo2 = algorithms.find(algoName2); algo2 != algorithms.end())
                {
                    // Input data from text file
                    int size;
                    int *a;
                    InputArrayFromTxtFile(a, size, argv[4]);

                    // Print input-data file-name
                    std::cout << "Input file: " << argv[4] << endl;

                    // Print input size
                    std::cout << "Input size: " << size << endl;

                    std::cout << "-------------------------\n";

                    // Measure running time
                    int runningTime1 = MeasureRunningTime(algo1->second, a, size);
                    int runningTime2 = MeasureRunningTime(algo2->second, a, size);

                    // Count comparison
                    ull countCompare1 = 0;
                    ull countCompare2 = 0;
                    algorithmsCount[algoName1](a, size, countCompare1);
                    algorithmsCount[algoName2](a, size, countCompare2);

                    // Print result
                    std::cout << "Running time: " << runningTime1 << " | " << runningTime2 << endl;
                    std::cout << "Comparisons: " << countCompare1 << " | " << countCompare2 << endl;

                    std::cout << "\n\n";

                    delete[] a;
                }
                else
                {
                    std::cout << "Algorithm 2 not found.\n";
                }
            }
            else
            {
                std::cout << "Algorithm 1 not found.\n";
            }
        }
        // Command 5
        else if (argc == 6)
        {
            if (auto algo1 = algorithms.find(algoName1); algo1 != algorithms.end())
            {
                if (auto algo2 = algorithms.find(algoName2); algo2 != algorithms.end())
                {
                    // We convert argv[4] to integer
                    int size = atoi(argv[4]);

                    // Print input size
                    std::cout << "Input size: " << size << endl;

                    // Get input order
                    std::string order = argv[5];

                    // Print input order
                    PrintOrderName(dataOrder[order]);

                    // Get order index
                    int orderIdx = dataOrder[order];

                    // Generate data
                    int *a = new int[size];
                    GenerateData(a, size, orderIdx);

                    // Write input data to text file
                    std::string textFileName = "input.txt";
                    WriteArrayToTxtFile(a, size, textFileName.c_str());

                    std::cout << "-------------------------\n";

                    // Measure running time
                    int runningTime1 = MeasureRunningTime(algo1->second, a, size);
                    int runningTime2 = MeasureRunningTime(algo2->second, a, size);

                    // Count comparison
                    ull countCompare1 = 0;
                    ull countCompare2 = 0;
                    algorithmsCount[algoName1](a, size, countCompare1);
                    algorithmsCount[algoName2](a, size, countCompare2);

                    // Print result
                    std::cout << "Running time: " << runningTime1 << " | " << runningTime2 << endl;
                    std::cout << "Comparisons: " << countCompare1 << " | " << countCompare2 << endl;

                    std::cout << "\n\n";

                    delete[] a;
                }
                else
                {
                    std::cout << "Algorithm 2 not found.\n";
                }
            }
            else
            {
                std::cout << "Algorithm 1 not found.\n";
            }
        }
        else
        {
            std::cout << "Error: Invalid number of arguments." << endl;
        }
    }
    else
    {
        std::cout << "Error: Flag cannot be found." << endl;
    }

    return 0;
}
