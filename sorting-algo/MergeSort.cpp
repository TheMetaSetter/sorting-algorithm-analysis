//
//  MergeSort.cpp
//  Sorting Algorithm Analysis
//
//  Created by Conqueror Mikrokosmos on 18/07/2023.
//

#include "SortingAlgorithms.hpp"

// Checked
//  Merge Sort
void Merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSortCore(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSortCore(a, l, m);
        MergeSortCore(a, m + 1, r);
        Merge(a, l, m, r);
    }
}

void MergeSort(int a[], int n)
{
    MergeSortCore(a, 0, n - 1);
}

// Hàm Merge giúp trộn hai mảng đã sắp xếp thành một mảng mới đã sắp xếp và cập nhật số lần so sánh.
void MergeCount(int a[], int left, int mid, int right, int &countCompare)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; ++countCompare && i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; ++countCompare && j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (++countCompare && i < n1 && ++countCompare && j < n2)
    {

        if (++countCompare && L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (++countCompare && i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (++countCompare && j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Hàm MergeSort chính với tham số tham chiếu countCompare
void MergeSortCountCompCore(int a[], int left, int right, int &countCompare)
{
    if (++countCompare && left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSortCountCompCore(a, left, mid, countCompare);
    MergeSortCountCompCore(a, mid + 1, right, countCompare);
    MergeCount(a, left, mid, right, countCompare);
}

void MergeSortCountComp(int a[], int n, int &countCompare)
{
    MergeSortCountCompCore(a, 0, n - 1, countCompare);
}