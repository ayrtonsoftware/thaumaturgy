//
//  Data.cpp
//  sorting
//
//  Created by Michael Bergamo on 3/19/19.
//  Copyright © 2019 Michael Bergamo. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include "Data.hpp"
using namespace std;

Data::Data(int _count) {
    count = _count;
    
    data = (count > 0) ? new int[count] : NULL;
}

Data::Data(Data& that) {
    count = that.count;
    data = (count > 0) ? new int[count] : NULL;
    if (count > 0) {
        for (int idx = 0; idx < count; idx++) {
            data[idx] = that[idx];
        }
    }
}

int &Data::operator[] (int index) {
    if (index >= 0 && index < count) {
        return data[index];
    }
    throw "Index out of range";
}

void Data::fill(int range) {
    if (count > 0 && data != NULL) {
        for (int idx = 0; idx < count; idx++) {
            data[idx] = rand() % range;
        }
    }
}

Data::~Data() {
    if (data != NULL) {
        delete [] data;
        data = NULL;
    }
}

int* Data::getData() {
    return data;
}

void Data::dumpData() {
    cout << "-----------------------" << endl;
    for (int idx = 0; idx < count; idx++) {
        cout << "Data[" << idx << "] = " << data[idx] << endl;
    }
}
