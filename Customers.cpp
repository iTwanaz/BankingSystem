//
//  Customers.cpp
//  BankingSystem
//
//  Created by Jieni Hou on 2015-10-07.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#include "Customers.h"

/******************************************************************************************************
    Customers Constructor
 ******************************************************************************************************/
Customers::Customers(){

}

/******************************************************************************************************
    Customers Deconstructor
 ******************************************************************************************************/
Customers::~Customers(){
    
}

/******************************************************************************************************
    loadCustomerBase loads the customer base
 ******************************************************************************************************/
void Customers::loadCustomerBase(){
    
    User cust;
    string str;
    string token;
    vector<string> list;
    ifstream infile;
    
    infile.open("customer.txt");
    
    // check for error
    if (infile.fail()){
        cerr << "Error loading file. Exiting Program." << endl;
        exit(1);
    }
    
    // go to a line of the file, read the string by separating each token and saving into list (vector)
    // load string
    while(getline(infile,str)){
        istringstream iss(str);
        //separate string and put into vector
        while(getline(iss,token,',')){
            list.push_back(token);
            }
        
        //set customer objects
        cust.setAccNum(stoi(list[0]));
        cust.setFname(list[1]);
        cust.setLname(list[2]);
        
        // for every 4th item and beyond, set account
        for(int i = 3; i < list.size(); i=i+2){
            Account acc;
            bankTotal = bankTotal + stod(list[i]) + stod(list[i+1]);
            acc.depositCheq(stod(list[i]));
            acc.depositSav(stod(list[i+1]));
            cust.addAccount(acc);
        }
        
        // put the set customer into the vector
        customers.push_back(cust);
        cust.clearAccounts();
        list.clear();
    }
    
    infile.close();
}

/******************************************************************************************************
    newCustomer writes the new customer information into the text file
 ******************************************************************************************************/
void Customers::newCustomer(User cust){
    
    Account acc;
    ofstream outfile;
    outfile.open("customer.txt",ios::app);
    
    if (outfile.fail()){
        cerr << "Error loading file. Customer not added" << endl;
        exit(1);
    }
    
    customers.push_back(cust);
    
    string customer = to_string(cust.getAccNum()) + "," + cust.getFname() + "," + cust.getLname();
    
    for (int i = 0; i < cust.numAccounts(); i ++){
        acc = cust.getAccount(i);
        customer = customer + "," + to_string(acc.getCheqBalance()) + "," + to_string(acc.getSavBalance());
    }
    
    outfile << customer;
    outfile.close();
    
    cout << "\nNew customer is now added";
}

/******************************************************************************************************
 deleteAnAccount deletes from the database of accounts and writes to a new file, then replaces the old file
 ******************************************************************************************************/
void Customers::deleteAnAccount(User cust){
    
    // find the customer within the data base
    // decrement bankTotal
    // delete their information
    // write the data base onto a new file, delete the old file.
    
    string line,token;
    vector<string> list;

    ifstream infile;
    infile.open("customer.txt");
    
    // check for error
    if (infile.fail()){
        cerr << "Error loading file. Exiting Program." << endl;
        exit(1);
    }
    
    ofstream out("temp.txt");
    while(getline(infile,line)) {
        istringstream iss(line);
        //separate string and put into vector
        while(getline(iss,token,',')){
            list.push_back(token);
        }
        if (list[0] != to_string(cust.getAccNum())){
            out << line << "\n";
        }
        list.clear();
    }
    
    infile.close();
    out.close();
    remove("customer.txt");
    rename("temp.txt","customer.txt");
    customers.clear();
    loadCustomerBase();
}

/******************************************************************************************************
    writeToAccount writes to the file the new customer modified information
 ******************************************************************************************************/
void Customers::writeToAccount(User cust, Account acc, int transfer){
    
    deleteAnAccount(cust);
    
    // increment bankTotal
    if (transfer != 1){
        bankTotal = bankTotal + (acc.getCheqBalance() + acc.getSavBalance());
    }
  

    ofstream customerBase;
    customerBase.open("customer.txt", ios::app);
    
    if (customerBase.fail()){
        cerr << "Error loading file." << endl;
        exit(1);
    }
    
    // locate the customer in the database, append their information to the end + the new information
    string data = "";
    data = data + to_string(cust.getAccNum()) + "," + cust.getFname() + "," + cust.getLname();
    Account acct;
    
    //loop thru for the number of accounts that the customer has
    for(int i = 0; i < cust.numAccounts(); i++ ) {
         acct = cust.getAccount(i);
        // check if the account is empty, if not, save it into the file
        if ( acct.getSavBalance() != 0 && acct.getCheqBalance() != 0){
         data = data + "," + to_string(acct.getCheqBalance()) + "," + to_string(acct.getSavBalance());
             }
         }
    
        data = data + "," + to_string(acc.getCheqBalance()) + "," + to_string(acc.getSavBalance());
        customerBase << data;
        customerBase.close();
    customers.clear();
    loadCustomerBase();
}

/******************************************************************************************************
    removeAccount removes an amount from the User's information
 ******************************************************************************************************/
void Customers::removeAmount(User cust, Account acc , int cheq){
    
    // delete that customer's information from data file
    deleteAnAccount(cust);
    
    // decrement bankTotal
    if (cheq == 1){
    bankTotal = bankTotal - acc.getCheqBalance();
    }
    else{
        bankTotal = bankTotal - acc.getSavBalance();
    }
    
    ofstream customerBase;
    customerBase.open("customer.txt", ios::app);
    
    if (customerBase.fail()){
        cerr << "Error loading file." << endl;
        exit(1);
    }
    
    // locate the customer in the database, append their information to the end + the new information
    string data = "";
    data = data + to_string(cust.getAccNum()) + "," + cust.getFname() + "," + cust.getLname();
    Account acct;
    
    //loop thru for the number of accounts that the customer has
    for(int i = 0; i < cust.numAccounts(); i++ ) {
        acct = cust.getAccount(i);
        // check if the account is empty, if not, save it into the file
        if ( acct.getSavBalance() != 0 && acct.getCheqBalance() != 0){
            data = data + "," + to_string(acct.getCheqBalance()) + "," + to_string(acct.getSavBalance());
        }
    }
    
    data = data + "," + to_string(acc.getCheqBalance()) + "," + to_string(acc.getSavBalance());
    customerBase << data;
    customerBase.close();
    customers.clear();
    loadCustomerBase();
}

/******************************************************************************************************
    viewAllAccounts prints all the customer accounts that are in the bank
 ******************************************************************************************************/
void Customers::viewAllAccounts(){
    
    cout << "\n";
    
    for(int i = 0; i < customers.size(); i++){
        cout << "Customer: " << i+1 << "\n";
        cout << customers[i].getAccNum() << "\t" << customers[i].getFname() << "\t" << customers[i].getLname() << "\n";
        customers[i].viewAllAccounts();
    }
    cout << "Total Customers: " << customers.size() << "\n";
    cout << "Total bank funds: " << bankTotal << "\n";
}

/******************************************************************************************************
    findCustomer finds a customer through verification, and if not found, returns an empty customer object
 ******************************************************************************************************/
User Customers::findCustomer(int accNum, string fName, string lName){
    User customer;
    bool isFound = false;
    // loop through customer base to find for match
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].getAccNum() == accNum && customers[i].getFname() == fName && customers[i].getLname() == lName){
            isFound = true;
            customer = customers[i];
        }
    }
    return customer;
}

/******************************************************************************************************
 findAccNum returns true when the account number is found in the database, false otherwise
 ******************************************************************************************************/
bool Customers::findAccNum(int accNum){
    // when its found, return the customer's information
    for(int i = 0; i < customers.size(); i++){
        if(accNum == customers[i].getAccNum()){
            return false;
        }
    }
    return true;
}