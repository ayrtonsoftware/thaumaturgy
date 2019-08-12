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
#include <chrono>
#include <ctime>

void print_timediff(const char* prefix, const struct timespec& start, const
                    struct timespec& end)
{
    double milliseconds = (end.tv_nsec - start.tv_nsec) / 1e6 + (end.tv_sec - start.tv_sec) * 1e3;
    printf("%s: %lf milliseconds\n", prefix, milliseconds);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <size>" << endl;
        return 1;
    }
    srand ((unsigned int)time(0));
    int size = atoi(argv[1]);
    cout << "Size: " << size << endl;
    
    Data dataBubble(size);
    dataBubble.fill(100);
    Data dataSelection(dataBubble);
    Data dataQuick(dataBubble);
    
    Sorter sorter(size);

    cout << "Sort:" << endl;
    cout << "# items to sort: " << size << endl;

    cout << endl << endl;

    struct timespec startBubble, endBubble;
    clock_gettime(CLOCK_MONOTONIC, &startBubble);
    int swapCountBubble = sorter.bubbleSort(dataBubble);
    clock_gettime(CLOCK_MONOTONIC, &endBubble);
    cout << "Total Swaps Bubble:     " << swapCountBubble << endl;
    print_timediff("Bubble: ", startBubble, endBubble);
    
    cout << endl << endl;
    
    struct timespec startSelection, endSelection;
    clock_gettime(CLOCK_MONOTONIC, &startSelection);
    int swapCountSelection = sorter.selectionSort(dataSelection);
    clock_gettime(CLOCK_MONOTONIC, &endSelection);
    cout << "Total Swaps Selection:  " << swapCountSelection << endl;
    print_timediff("Selection: ", startSelection, endSelection);

    cout << endl << endl;
    
    struct timespec startQuick, endQuick;
    clock_gettime(CLOCK_MONOTONIC, &startQuick);
    sorter.quickSort(dataQuick);
    int swapCountQuick = sorter.getSwapCount();
    clock_gettime(CLOCK_MONOTONIC, &endQuick);
    cout << "Total Swaps Quick:  " << swapCountQuick << endl;
    print_timediff("Quick: ", startQuick, endQuick);
    dataQuick.dumpData();

    return 0;
}
