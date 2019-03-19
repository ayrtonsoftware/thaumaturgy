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
public:
    Sorter(int _size);
    int bubbleSort(Data& data);
    int selectionSort(Data& data);
};

#endif /* sorter_hpp */
