//
//  DoubleItem.hpp
//  ch4_breakout
//
//  Created by Steve Yang on 9/14/21.
//

#ifndef DoubleItem_hpp
#define DoubleItem_hpp

#include <stdio.h>

class DoubleItem
{
public:
    DoubleItem(double original); // Constructor
    ~DoubleItem(); // Destructor
    
private:
    double TheDouble; // private member variable
};

#endif /* DoubleItem_hpp */
