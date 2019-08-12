//
//  main.cpp
//  HeightMap
//
//  Created by Michael Bergamo on 4/18/19.
//  Copyright © 2019 Michael Bergamo. All rights reserved.
//

#include <iostream>

int water1(int *map, int count) {
    int total = 0;
    int running = 0;
    int currentHeight = 0;
    int currentHeightIndex = -1;
    
    for (int i = 0; i < count; i++) {
        if (map[i] > currentHeight) {
            currentHeight = map[i];
            currentHeightIndex = i;
            total += running;
            running = 0;
        } else {
            running += (currentHeight - map[i]);
        }
    }
    total += running;
    
    if (map[count-1] < currentHeight) {
        int adjustment = currentHeight - map[count-1];
        for (int i = count-1; i > currentHeightIndex; i--) {
            total -= adjustment;
        }
    }
    
    return total;
}

int water2(int *map, int count) {
    int total = 0;
    int running = 0;
    int rcount = 0;
    int currentHeight = 0;
    int currentHeightIndex = -1;
    
    for (int i = 0; i < count; i++) {
        if (map[i] > currentHeight) {
            currentHeight = map[i];
            currentHeightIndex = i;
            total += running;
            running = 0;
            rcount = 0;
        } else {
            running += (currentHeight - map[i]);
            rcount++;
        }
    }
    total += running;
    int lastHeight = map[count-1];
    if (map[count-1] < currentHeight) {
        int adjustment = currentHeight - map[count-1];
        for (int i = count-1; i > currentHeightIndex; i--) {
            if (map[i] > lastHeight) {
                total -= (map[i]-lastHeight);
            }
        }
    }
    return total;
}

int water(int *map, int count) {
    int total = 0;
    int running = 0;
    int rcount = 0;
    int currentHeight = 0;
    int currentHeightIndex = -1;
    
    for (int i = 0; i < count; i++) {
        if (map[i] > currentHeight) {
            currentHeight = map[i];
            currentHeightIndex = i;
            total += running;
            running = 0;
            rcount = 0;
        } else {
            running += (currentHeight - map[i]);
            rcount++;
        }
    }
    total += running;
    int adjustment = currentHeight - map[count-1];
    total -= (adjustment * rcount);
    return total;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int map[] = {20, 10, 5, 5, 10, 5, 5, 6};
    int total = water(map, 8);
    printf("total = %d\n", total);
    
    int map2[] = {10, 20, 5, 5, 10, 5, 5, 10, 15};
    int total2 = water(map2, 9);
    printf("total = %d\n", total2);

    
    return 0;
}
