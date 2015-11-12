//
//  Customers.h
//  BankingSystem
//
//  Created by Jieni Hou on 2015-10-07.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#ifndef __BankingSystem__Customers__
#define __BankingSystem__Customers__

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Account.h"

using namespace std;

class Customers{
    private:
    vector <User> customers;
    double bankTotal;
    
    public:
    Customers();
    ~Customers();
    void loadCustomerBase();
    void deleteAnAccount(User cust);
    void writeToAccount(User cust, Account acc, int transfer);
    void removeAmount(User cust, Account acc, int cheq);
    void newCustomer(User cust);
    void viewAllAccounts();
    User findCustomer(int accNum, string fName, string lName);
    bool findAccNum(int accNum);
    
};

#endif /* defined(__BankingSystem__Customers__) */
