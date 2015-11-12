//
//  Maintenance.h
//  BankingSystem
//
//  Created by Jieni Hou on 2015-10-09.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#ifndef __BankingSystem__Matenance__
#define __BankingSystem__Matenance__

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "User.h"

using namespace std;

class Maintenance{
private:
    vector <User> maintenances;
    void loadMaintenanceBase();
    
public:
   Maintenance();
    ~Maintenance();
    string printTime();
    User findMaintenance(int accNum, string fName, string lName);
};


#endif /* defined(__BankingSystem__Matenance__) */
