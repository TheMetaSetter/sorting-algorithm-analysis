// https://github.com/HaiDuc0147/sortingAlgorithm/blob/main/reportSort/Sort.cpp

#include "sorting-algo/SortingAlgorithms.hpp"
#include "helper/Helper.hpp"
#include <chrono>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <fstream>

//Library to measure running time of a function
using namespace std::chrono;

std::unordered_map<std::string, std::function<void(int *, int)>>
    algorithms = {
        {"insertion-sort", InsertionSort},
        {"counting-sort", CountingSort},
        {"flash-sort", FlashSort}};

std::unordered_map<std::string, std::function<void(int *, int, int &)>>
    algorithms_count = {
        {"insertion-sort", InsertionSortCountComp},
        {"counting-sort", CountingSortCountComp},
        {"flash-sort", FlashSortCountComp}};

int main(int argc, const char * argv[])
{

    std::string name = argv[2];

    if (strcmp(argv[1], "-c") == 0)
    {
        if (argc == 4)
        {
            if (auto algo = algorithms.find(name); algo != algorithms.end())
            {
                // auto start = steady_clock::now();
                // algo->second(a, SIZE);
                // auto end = steady_clock::now();
                // std::cout << "Runtime: " << duration_cast<microseconds>(end - start).count() << "us\n";

                // int countCompare = 0;
                // algorithms_count[name](a, SIZE, countCompare);
                
                //The 'atoi' function return 0 if the cstring cannot be converted to integer.
                int checkChar = atoi(argv[3]);
                if (checkChar == 0) {
                    int n;
                    int *a;
                    InputArrayFromTxtFile(a, n, argv[3]);
                }

            }
            else
            {
                std::cout << "Algorithm not found!\n";
            }
        }
        else if (argc == 5)
        {
            if (auto algo = algorithms.find(name); algo != algorithms.end())
            {
                // auto start = steady_clock::now();
                // algo->second(a, SIZE);
                // auto end = steady_clock::now();
                // std::cout << "Runtime: " << duration_cast<microseconds>(end - start).count() << "us\n";
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
