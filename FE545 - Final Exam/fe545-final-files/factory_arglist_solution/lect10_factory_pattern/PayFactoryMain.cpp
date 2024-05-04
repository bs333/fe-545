//
//  main.cpp
//  ch10_factory_pattern
//
//  Created by cheerzzh on 24/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "ArgList.h"
#include "PayOff3.h"
#include "PayOffConstructible.h"
#include "PayOffBridge.h"
#include "PayOffFactory.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    
    
    double Strike1, Strike2;
    std::string name;
    
    cout << "Enter strike 1\n";
    cin >> Strike1;
    
    cout << "Enter strike 2\n";
    cin >> Strike2;
    
    ArgumentList args("myArgs");
    args.add("strike1", Strike1);
    args.add("strike2", Strike2);

    cout << "\npay-off name\n";
    cin >> name;
    
    PayOff* PayOffPtr =
    PayOffFactory::Instance().CreatePayOff(name,args);
    
    if (PayOffPtr != NULL)
    {
        double Spot;
        cout << "\nspot\n";
        cin >> Spot;
        
        cout << "\n" << PayOffPtr->operator ()(Spot) << "\n";
        delete PayOffPtr;
    }
    
    double tmp;
    cin >> tmp;
    
    return 0;
}
