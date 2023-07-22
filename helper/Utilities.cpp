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
void InputArrayFromTxtFile(int *&a, int &n, const char *filename)
{
    std::ifstream fin(filename);
    fin >> n;

    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }
}

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // NEED TO FIX
        std::cout << a[i] << " ";
        //----------------
    }
    std::cout << std::endl;
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

int MeasureRunningTime(std::function<void(int *, int)> algoFunc, int a[], int size)
{
    auto start = steady_clock::now();
    algoFunc(a, size);
    auto end = steady_clock::now();
    int runningTime = duration_cast<microseconds>(end - start).count(); // in microseconds (μs)

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