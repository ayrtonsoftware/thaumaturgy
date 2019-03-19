//
//  Data.hpp
//  sorting
//
//  Created by Michael Bergamo on 3/19/19.
//  Copyright © 2019 Michael Bergamo. All rights reserved.
//

#ifndef Data_hpp
#define Data_hpp

class Data {
    int count;
    int *data;
public:
    Data(int _count);
    Data(Data& that);
    ~Data();
    int* getData();
    void dumpData();
    void fill();
    int &operator[] (int); 
};

#endif /* Data_hpp */
