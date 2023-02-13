#pragma once

#include <iostream>
#include <vector>

using namespace std;

#pragma region merge_sort

void merge(vector<int>& arr, const int& start, const int& end) {
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;

    vector<int> temp;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j])
            temp.emplace_back(arr[i++]);
        else
            temp.emplace_back(arr[j++]);
    }

    while (i <= mid) temp.emplace_back(arr[i++]);
    while (j <= end) temp.emplace_back(arr[j++]);

    int k = 0;
    for (int idx = start; idx <= end; ++idx)
        arr[idx] = temp[k++];
}

void merge_sort(vector<int>& arr, const int& start, const int& end) {
    if (start >= end) return;

    const int mid = (start + end) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    merge(arr, start, end);
}

#pragma endregion

#pragma region quick_sort

void quick_sort(vector<int>& arr, const int& start, const int& end) {
    if (start >= end) return;

    int pivot = arr[start];
    int left = start + 1;
    int right = end;

    while (left < right) {
        while (pivot >= arr[left]) left++;
        while (pivot < arr[right]) right--;

        if (left < right) swap(arr[left], arr[right]);
    }

    swap(pivot, arr[right]);

    quick_sort(arr, start, right - 1);
    quick_sort(arr, right + 1, end);
}

#pragma endregion

#pragma region binary_search

//template<typename _Ty>
//bool binary_search(_Ty)

#pragma endregion