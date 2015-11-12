//
//  Managers.h
//  BankingSystem
//
//  Created by Jieni Hou on 2015-10-09.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#ifndef __BankingSystem__Managers__
#define __BankingSystem__Managers__

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "User.h"

using namespace std;

class Managers{
private:
    vector <User> managers;
    void loadManagerBase();
    
public:
    Managers();
    ~Managers();
    User findManager(int accNum, string fName, string lName);
};


#endif /* defined(__BankingSystem__Managers__) */
