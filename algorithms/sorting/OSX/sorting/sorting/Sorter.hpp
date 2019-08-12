//
//  sorter.hpp
//  sorting
//
//  Created by Michael Bergamo on 3/19/19.
//  Copyright © 2019 Michael Bergamo. All rights reserved.
//

#ifndef sorter_hpp
#define sorter_hpp
#include "Data.hpp"

class Sorter {
    int size;
    int swapCount;
public:
    Sorter(int _size);
    int bubbleSort(Data& data);
    int selectionSort(Data& data);
    int quickSort(Data& data);
    int getSwapCount() {
        return swapCount;
    }
private:
    void swap(Data& data, int i, int j);
    int partition(Data& data, int lo, int hi);
    void quickSort(Data& data, int lo, int hi);
};

#endif /* sorter_hpp */
