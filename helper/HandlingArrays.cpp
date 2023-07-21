//
//  HandlingArrays.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 19/07/2023.
//

#include <iostream>
#include "Helper.hpp"
#include <fstream>
#include <string_view>

using namespace std;

void InputArrayFromTxtFile(int a[], int &n, const char* filename)
{
    ifstream fin(filename);
    fin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
}

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
