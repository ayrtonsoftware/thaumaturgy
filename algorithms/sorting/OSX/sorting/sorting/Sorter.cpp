//
//  sorter.cpp
//  sorting
//
//  Created by Michael Bergamo on 3/19/19.
//  Copyright © 2019 Michael Bergamo. All rights reserved.
//

#include "Sorter.hpp"
#include <limits>
using namespace std;

Sorter::Sorter(int _size) {
    size = _size;
}

int Sorter::bubbleSort(Data& data) {
    int swapCount = 0;
    for (int outer = 0; outer < size-1; outer++) {
        for (int inner = 0; inner < size-outer-1; inner++) {
            if (data[inner] > data[inner+1]) {
                swapCount++;
                int temp = data[inner+1];
                data[inner+1] = data[inner];
                data[inner] = temp;
            }
        }
    }
    return swapCount;
}

int Sorter::selectionSort(Data& data) {
    int swapCount = 0;
    
    int unsorted = 0;
    while (unsorted < size) {
        int min = data[unsorted];
        int minIndex = unsorted;
        for (int inner = unsorted+1; inner < size; inner++) {
            if (data[inner] < min) {
                min = data[inner];
                minIndex = inner;
            }
        }
        if (minIndex != unsorted) {
            swapCount++;
            int temp = data[unsorted];
            data[unsorted] = data[minIndex];
            data[minIndex] = temp;
        }
        unsorted++;
    }
    
    return swapCount;
}

void Sorter::swap(Data& data, int i, int j) {
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int Sorter::partition(Data& data, int lo, int hi) {
    int pivot = data[hi];
    int i = lo;
    for (int j = lo; j < hi - 1; j++) {
        if (data[j] < pivot) {
            swap(data, i, j);
            i++;
            swapCount++;
        }
    }
    swap(data, i, hi);
    return i;
}

void Sorter::quickSort(Data& data, int lo, int hi) {
    if (lo < hi) {
        int p = partition(data, lo, hi);
        swapCount += partition(data, lo, p-1);
        swapCount += partition(data, p+1, hi);
    }
}

int Sorter::quickSort(Data& data) {
    swapCount = 0;
    quickSort(data, 0, size-1);
    return swapCount;
}
