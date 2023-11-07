//
//  HandlingArrays.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 19/07/2023.
//

// File .hpp containing function initialization
#include "Helper.hpp"

// Built-in libraries used in this source
#include <iostream>
#include <fstream>
#include <string_view>
#include <chrono>
#include <cstring>

// To use steady_clock
using namespace std::chrono;

// This function need to use *&a to change the value of pointer a. This is called "reference to pointer".
void InputArrayFromTxtFile(int *&a, int &n, const char *fileName)
{
    std::ifstream fin(fileName);
    fin >> n;

    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }

    fin.close();
}

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void WriteArrayToTxtFile(int *a, int n, const char *fileName)
{
    std::ofstream fout(fileName);
    
    fout << n << "\n";

    for (int i = 0; i < n; i++)
    {
        fout << a[i] << " ";
    }

    fout.close();
}

// Print result
void PrintResult(const char *outPara, int runningTime, ull countCompare)
{
    bool printRunTime = false;
    bool printCountCompare = false;
    printRunTime = strcmp(outPara, "-time") == 0 ? true : false;
    printCountCompare = strcmp(outPara, "-comp") == 0 ? true : false;
    if (strcmp(outPara, "-both") == 0)
    {
        printRunTime = true;
        printCountCompare = true;
    }

    if (printRunTime)
    {
        std::cout << "Running time (if required): " << runningTime << " μs\n";
    }

    if (printCountCompare)
    {
        std::cout << "Comparisons (if required): " << countCompare << " comparisons\n";
    }
}

ull MeasureRunningTime(std::function<void(int *, int)> algoFunc, int a[], int size)
{
    auto start = steady_clock::now();
    algoFunc(a, size);
    auto end = steady_clock::now();
    ull runningTime = duration_cast<microseconds>(end - start).count(); // in microseconds (μs)

    return runningTime;
}

void PrintOrderName(int orderIdx)
{
    std::cout << "Input order: ";

    switch (orderIdx)
    {
    case 0:
        std::cout << "Randomize";
        break;
    case 1:
        std::cout << "Sorted";
        break;
    case 2:
        std::cout << "Reversed";
        break;
    case 3:
        std::cout << "Nearly Sorted";
        break;
    default:
        break;
    }

    std::cout << "\n-------------------------\n";
}

void WriteExperimentalResultToCsvFile(std::string algoName, int orderIdx, int inputSize , int runningTime, ull countCompare)
{   
    std::ofstream fout;

    std::string inputSizeStr = std::to_string(inputSize);

    std::string pathToResults = "experimental_results/";

    if (orderIdx == 0) {
        pathToResults += "randomized_data/";
    }
    else if (orderIdx == 1) {
        pathToResults += "sorted_data/";
    }
    else if (orderIdx == 2) {
        pathToResults += "reverse_sorted_data/";
    }
    else if (orderIdx == 3) {
        pathToResults += "nearly_sorted_data/";
    }

    pathToResults += inputSizeStr;
    pathToResults += ".csv";

    fout.open(pathToResults, std::ios::app);

    fout << std::endl << algoName << "," << runningTime << "," << countCompare;

    fout.close();
}