//
//  main.cpp
//  sorting
//
//  Created by Michael Bergamo on 3/19/19.
//  Copyright © 2019 Michael Bergamo. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;
#include "Data.hpp"
#include "Sorter.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <size>" << endl;
        return 1;
    }
    srand ((unsigned int)time(0));
    int size = atoi(argv[1]);
    cout << "Size: " << size << endl;
    
    Data dataBubble(size);
    dataBubble.fill();
    Data dataSelection(dataBubble);
    
    Sorter sorter(size);

    int swapCountBubble = sorter.bubbleSort(dataBubble);
    int swapCountSelection = sorter.selectionSort(dataSelection);
    
    cout << "Sort:" << endl;
    cout << "# items to sort: " << size << endl;
    cout << "Total Swaps Bubble:     " << swapCountBubble << endl;
    cout << "Total Swaps Selection:  " << swapCountSelection << endl;
    return 0;
}
