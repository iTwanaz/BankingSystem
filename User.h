//
//  User.h
//  BankingSystem
//
//  Created by Jieni Hou on 2015-09-28.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#ifndef __BankingSystem__User__
#define __BankingSystem__User__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Account.h"

using namespace std;

class User
{
private:
    vector<Account> accounts;
    int accountNum;
    string fName;
    string lName;
    
public:
    User(int accNum, string first, string last);
    User();
    ~User();
    void setFname(string firstN);
    void setLname(string lastN);
    void setAccNum(int accNum);
    int getAccNum();
    string getFname();
    string getLname();
    long numAccounts();
    void addAccount(Account acc);
    Account getAccount(int number);
    void viewAllAccounts();
    void clearAccounts();
    
};

#endif /* defined(__BankingSystem__User__) */
