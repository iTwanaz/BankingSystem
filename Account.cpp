//
//  Account.cpp
//  BankingSystem
//
//  Created by Jieni Hou on 2015-09-28.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#include "Account.h"

using namespace std;

/******************************************************************************************************
 Account Constructor
 ******************************************************************************************************/
Account::Account():cheqBalance(0), savBalance(0){
}

/******************************************************************************************************
 Account Constructor
 ******************************************************************************************************/
Account::Account(double cheq, double sav):cheqBalance(cheq), savBalance(sav){
}

/******************************************************************************************************
 Account deconstructor
 ******************************************************************************************************/
Account::~Account(){
}

/******************************************************************************************************
 depositSav saves the amount deposited into savings balance
 ******************************************************************************************************/
void Account::depositSav(double amount){
    savBalance += amount;
}

/******************************************************************************************************
 depositCheq saves the amount deposited into chequing balance
 ******************************************************************************************************/
void Account::depositCheq(double amount){
    cheqBalance += amount;
}

/******************************************************************************************************
 getSavBalance gets the savings balance
 ******************************************************************************************************/
double Account::getSavBalance(){
    return savBalance;
}

/******************************************************************************************************
 getCheqBalance gets the chequings balance
******************************************************************************************************/
double Account::getCheqBalance(){
    return cheqBalance;
}

/******************************************************************************************************
    withdrawSav takes in an amount to withdraw, then prints the amount that is now withdrawn from the account
 ******************************************************************************************************/
void Account::withdrawSav(double amount){

    if(amount > getSavBalance()){
      cout << "Withdraw was unsuccessful. Balance is not enough to withdraw.\n";
    }
    else{
        savBalance = savBalance - amount;
        double balance = getSavBalance();
        cout << "Your new balance in Savings is: " << balance << "\n";
    }
}

/******************************************************************************************************
    withdrawCheq takes in an amount to withdraw, then prints the amount that is now withdrawn from the account
 ******************************************************************************************************/
void Account::withdrawCheq(double amount){
    int confirm = 0;
    
    // same concept as transfer.
    if(amount < getCheqBalance()){
        if (getCheqBalance() - amount > THRESHOLD){
        cheqBalance -= amount;
        cout << "Your new balance in Chequing is: " << getCheqBalance() << "\n";
        }
        else{
        cout << "Are you sure you would like to withdraw? You will be charged an extra $2 fee for transactions that will cause your account to be below $1000" << "\n" << "1. Yes\n2. No\n";
        cin >> confirm;
        if (confirm == 1){
            cheqBalance -= amount;
            cheqBalance -= FEE;
            cout << "Your new balance in Chequing is: " << getCheqBalance() << "\n";
        }
        else if (confirm == 2){
            cout << "Withdraw is cancelled.\n";
        }
        else{
            cout << "Withdraw is not done due to invalid input.\n";
        }
      }
    }
    else{
        cout << "Withdraw was unsuccessful. Balance is not enough to withdraw.\n";
    }
}

/*****************************************************************************************************
    transferSav method transfers from savings to chequing the specified amount from the user
 *****************************************************************************************************/
void Account::transferSav(double amount){
    if(amount < getSavBalance()){
        savBalance -= amount;
        cheqBalance += amount;
        cout << "Transfer was successful.\nSavings: " << getSavBalance() << "\nChequing: " << getCheqBalance() << "\n";

    }
    else{
        cout << "Transfer was unsuccessful. Balance is not enough to transfer.\n";
    }
}

/******************************************************************************************************
    transferCheq method transfers from savings to chequing the specified amount from the user
 ******************************************************************************************************/
void Account::transferCheq(double amount){
    int confirm = 0;
    
    // 1. check if the amount is less than the amount in chequing.
    if(amount < getCheqBalance()){
        // 2. check if the current chequing subtracted by amount would fall below threshold (1000)
       if (getCheqBalance() - amount > THRESHOLD){
        cheqBalance -= amount;
        savBalance += amount;
        cout << "Transfer was successful.\nSavings: " << getSavBalance() << "\nChequing: " << getCheqBalance() << "\n";
       }
       else{
        cout << "Are you sure you would like to transfer?\nYou will be charged an extra $2 fee for\ntransactions that will cause your account to be below $1000" << "\n" << "1. Yes\n2. No\n";
        cin >> confirm;
        if (confirm == 1){
            cheqBalance -= amount;
            cheqBalance -= FEE;
            savBalance += amount;
            cout << "Transfer was successful. Savings: " << getSavBalance() << "\nChequing: " << getCheqBalance() << "\n";
        }
        else if (confirm == 2){
            cout << "Transfer is cancelled.\n";
        }
        else{
            cout << "Transfer is not done due to invalid input.\n";
        }
       }
    }
       else{
        cout << "Transfer was unsuccessful. Balance is not enough to transfer.\n";
    }
}

/******************************************************************************************************
    zeroAccounts zeros out all accounts by setting them to 0
 ******************************************************************************************************/
void Account:: zeroAccounts(){
  cheqBalance = 0;
  savBalance = 0;
}

/******************************************************************************************************
    accountInformation prints all the information of the account onto screen
 ******************************************************************************************************/
void Account::accountInformation(){
    
    cout << fixed << setprecision(2) << "Balance in Savings: " << getSavBalance() << "\nBalance in Chequing: " << getCheqBalance()<<"\n";
}

/******************************************************************************************************
    closeAccount returns 1 if closing was successful, returns 0 if closing was unsuccessful
*******************************************************************************************************/
int Account::closeAccount(){
    if (getSavBalance() != 0 && getCheqBalance() != 0){
        cout << "Account balances are not zero. Closing was unsuccessful.";
        return 0;
    }
    else{
        zeroAccounts();
        return 1;
    }
    
}
