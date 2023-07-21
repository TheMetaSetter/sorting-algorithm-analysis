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

void InputArrayFromTxtFile(int a[], int &n, const char *filename)
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
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

// Print result
void PrintResult(const char *outPara, int runningTime, int countCompare)
{
    bool printRunTime = false;
    bool printCountCompare = false;
    printRunTime = strcmp(outPara, "-time") ? true : false;
    printCountCompare = strcmp(outPara, "-comp") ? true : false;
    if (strcmp(outPara, "-both"))
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