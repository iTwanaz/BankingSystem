//
//  Account.h
//  BankingSystem
//
//  Created by Jieni Hou on 2015-09-28.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#ifndef __BankingSystem__Account__
#define __BankingSystem__Account__

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Account
{
private:
    double cheqBalance;
    double savBalance;
    
public:
    static const int FEE = 2;
    static const int THRESHOLD = 1000;
    Account(double cheq, double sav);
    Account();
    ~Account();
    void depositSav(double amount);
    void depositCheq(double amount);
    double getSavBalance();
    double getCheqBalance();
    void withdrawSav(double amount);
    void withdrawCheq(double amount);
    void transferSav(double amount);
    void transferCheq(double amount);
    void zeroAccounts();
    void accountInformation();
    int closeAccount();
    
    };
    
#endif /* defined(__BankingSystem__Account__) */
