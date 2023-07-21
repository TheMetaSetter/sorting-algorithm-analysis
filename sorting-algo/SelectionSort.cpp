//
//  SelectionSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

// Hàm Swap giúp hoán đổi giá trị giữa hai biến.
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm SelectionSort chính
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        // Đưa phần tử nhỏ nhất về đầu mảng chưa sắp xếp
        Swap(arr[i], arr[minIdx]);
    }
}


// Hàm SelectionSort với tham số tham chiếu countCompare
void SelectionSortCountComp(int arr[], int n, int &countCompare) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp và cập nhật số lần so sánh.
        for (int j = i + 1; j < n; j++) {
            // Cộng thêm 1 lần so sánh khi tiến hành so sánh các phần tử.
            countCompare++;

            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        // Đưa phần tử nhỏ nhất về đầu mảng chưa sắp xếp
        Swap(arr[i], arr[minIdx]);
    }
}

