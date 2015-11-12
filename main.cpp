//
//  main.cpp is the main program.
//  Jieni's Banking System
//
//  Created by Jieni Hou on 2015-09-22.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "User.h"
#include "Account.h"
#include "Customers.h"
#include "Managers.h"
#include "Maintenance.h"

using namespace std;

int choice = 0;         // for varied choices
int choice2 = 0;        // stores the user's initial login choice
int login = 0;
bool isChoice = false;
bool isLoggedIn = false;
bool isCustomer = false;
bool isManager = false;
bool isMaintenance = false;
bool _isTraceOn = false;
bool isBack = true;
bool fullExit = true;

Customers cust;
Managers man;
Maintenance maint;

User customer;
User manager;
User maintenance;
string fName,lName;
int accountNum;


int main(int argc, const char * argv[]) {
    ofstream outfile;
    outfile.open("trace.txt",ios::app);
    outfile << maint.printTime() << "\n";  // print time of trace
    cust.loadCustomerBase();
    while(isBack){
    isLoggedIn = false;
    isChoice = false;
    fullExit = true;

    cout << "\n******* Welcome to Jieni's Bank! *******\n"<<"\nChoose an option below to begin banking:\n"<< endl;
    cout << "1. Customer Login\n";
    cout << "2. Manager Login\n";
    cout << "3. System Maintenance\n";
    cout << "4. Exit\n";
    cout << "\n****************************************\n";
    
    //*Open the bank file to start session*
    while(!isChoice){
         cin >> choice;
        switch(choice){
   // Customer login information screens
            case 1:
                isChoice = true;
                 break;
            case 2:
                 isChoice = true;
                 break;
            case 3:
                 isChoice = true;
                 break;
            case 4:
                isChoice = true;
                isLoggedIn = true;
                isBack = false;
                fullExit = false;
                break;
                
            default:
                choice = 0;
                cout << "You've typed in an invalid option, try again." << endl;
                break;
        }
    }
        while(fullExit){
    /* login verification */
    isChoice = false;
    cout << "\n************ Jieni's Bank! *************\n"<<"\nChoose an option below:\n"<< endl;
    cout << "1. Login\n";
    // *Maybe add an additional option to recover forgotten account number*
    cout << "\n****************************************\n";
    
    while(!isChoice){
        cin >> login;
        switch(login){
                // login information screens
            case 1:
                isChoice = true;
                break;
            
            default:
                cout << "You've typed in an invalid option, try again." << endl;
                break;
        }
    }
    // *Might want to record the action of selecting a certain choice (by recording the choice number and prompting to execution trace*
    
    /* check each entry for validity */
    isChoice = false;
     // while you dont enter any information that is wrong
    while(!isChoice){
        switch(choice){
        //Customer logging in
        case 1:
            while(!isCustomer){
                cout << "\n************ Jieni's Bank! *************\n"<< endl;
                cout << "Please enter your account number:\n";
                cin >> accountNum;
                cout << "Please enter your first name:\n";
                cin >> fName;
                cout << "Please enter your last name:\n";
                cin >> lName;
                cout << "\n****************************************\n";
            
            /* do validation check with if and else statements, remember to set isCustomer to true if true */
                customer = cust.findCustomer(accountNum,fName,lName);
                if (customer.getAccNum() != -1 && customer.getFname() == fName && customer.getLname() == lName){
                    isCustomer = true;
                    login = 1;
                    if(_isTraceOn){
                        outfile << customer.getAccNum() << "\n" << customer.getFname() << "\n" << customer.getLname() << " is now logged in 1\n";
                    }
                }
                else{
                    cout << "Login Unsuccessful. Please Try Again.\n";
                }
                }
            isChoice = true;
            fullExit = false;
            break;
          
        //Manager logging in
        case 2:
            while(!isManager){
                cout << "\n************ Jieni's Bank! *************\n"<< endl;
                cout << "Please enter the account number:\n";
                cin >> accountNum;
                cout << "Please enter the first name:\n";
                cin >> fName;
                cout << "Please enter the last name:\n";
                cin >> lName;
                cout << "\n****************************************\n";
                
                /* do validation check with if and else statements, remember to set isManager to true if true */
                
                manager = man.findManager(accountNum,fName,lName);
                if ((manager.getAccNum() != -1) && manager.getFname() == fName && manager.getLname() == lName){
                    isManager = true;
                    login = 1;
                }
                else{
                    cout << "Login Unsuccessful. Please Try Again.\n";
                }
                }
            isChoice = true;
            fullExit = false;
            break;
         
        //Systems Admin loggin in
        case 3:
                while(!isMaintenance){
                    cout << "\n************ Jieni's Bank! *************\n"<< endl;
                    cout << "Please enter your account number:\n";
                    cin >> accountNum;
                    cout << "Please enter your first name:\n";
                    cin >> fName;
                    cout << "Please enter your last name:\n";
                    cin >> lName;
                    cout << "\n****************************************\n";
                    
                    /* do validation check with if and else statements, remember to set isMaintenanceto true if true */
                    maintenance = maint.findMaintenance(accountNum,fName,lName);
                    if ((maintenance.getAccNum() == accountNum) && maintenance.getFname() == fName && maintenance.getLname() == lName){
                        isMaintenance = true;
                        login = 1;
                    }
                    else{
                        cout << "Login Unsuccessful. Please Try Again.\n";
                    }
                }
                isChoice = true;
                fullExit = false;
                break;
        default:
            isChoice = true;
            break;
        }
    }
        }
    //*Account Pages*
    // By the time we reach this stage, we will already know if the manager, customer or maintenance person is logged in. So now we just need
    //to print a different account page for each user.
    
    /*Customer page*/
    choice = 0;
    int accountNum = 0;
    bool isChosen = true;
    bool isAccounts = true;
    bool isCheck = true;
    bool savings = true;
    bool chequing = true;
    bool access = true;
    bool accValid = true;
    double depo = 0;
    double withdraw = 0;
    double transfer = 0;
    double cheq = 0;
    double sav = 0;
    Account custAcc;
    
    while (!isLoggedIn){
        
        // Customer account page
        while(isCustomer){
            isAccounts = true;
            isChosen = true;
            accValid = true;
            while (accValid){
            cout <<"\n************ Jieni's Bank! *************\n" << endl;
            
            cout <<"Welcome " << customer.getFname() << "!\n"<< endl; // *print the user's name*
            cout <<"Which account would you like to access today?\n\n";
            customer.viewAllAccounts();
            cout <<"Please type in the number that you would like to access.\n ";
            cout << "\n****************************************\n";
            cin >> choice;

            accountNum = choice;
            custAcc = customer.getAccount(choice);
            if (custAcc.getSavBalance() != 0 && custAcc.getCheqBalance() != 0){
                accValid = false;
            }
            }
            
            while(isAccounts){
                isChosen = true;
                choice = 0;
            cout <<"\n************ Jieni's Bank! *************\n" << endl;
            cout << "Account #: " << accountNum << "\n\n";
            cout <<"1. Savings\n2. Chequing\n3. Change Account\n4. Exit\n";
            cout << "\n****************************************\n";
            cin >> choice;
          
            while(isChosen){
            switch(choice){
                /*operations with savings account*/
                case 1:
                    if(_isTraceOn){
                        outfile << "Customer chose savings 1\n";
                    }
                    while(savings){
                        choice = 0;
                    cout <<"\n************ Jieni's Bank! *************\n" << endl;
                    cout <<"You are currently in your Savings.\nYour balance in savings is: " << custAcc.getSavBalance() << "\n\n";
                    cout <<"1. Deposit\n2. Withdraw\n3. Transfer from savings to chequing\n4. Back\n ";
                    cout << "\n****************************************\n";
                    cin >> choice;
                 
                    switch(choice){
                        case 1:
                            if(_isTraceOn){
                                outfile << "Customer chose to deposit in savings 1\n";
                            }
                            cout<< "\n************ Jieni's Bank! *************\n" << endl;
                            cout <<"Please enter amount to deposit:\n ";
                            cin >> depo;
                            custAcc.depositSav(depo);
                            cout << "The amount is now deposited. Your Savings balance is: " << custAcc.getSavBalance() << "\n";
                            cout << "\n****************************************\n";
                            cust.writeToAccount(customer,custAcc,0);
                            break;
                        
                        case 2:
                            if(_isTraceOn){
                                outfile << "Customer chose to withdraw in savings 2\n";
                            }
                            cout<< "\n************ Jieni's Bank! *************\n" << endl;
                            cout <<"Please enter amount to withdraw:\n ";
                            cin >> withdraw;
                            custAcc.withdrawSav(withdraw);
                            cout << "\n****************************************\n";
                            cust.removeAmount(customer, custAcc , 1);
                            break;
                            
                        case 3:
                            if(_isTraceOn){
                                outfile << "Customer chose to transfer in savings 3\n";
                            }
                            cout<< "\n************ Jieni's Bank! *************\n" << endl;
                            cout <<"Please enter amount to transfer:\n ";
                            cin >> transfer;
                            custAcc.transferSav(transfer);
                            cout << "\n****************************************\n";
                            cust.writeToAccount(customer,custAcc,1);
                            break;
                        
                        case 4:
                            if(_isTraceOn){
                                outfile << "Customer changed accounts 4\n";
                            }
                            isChosen = false;
                            savings = false;
                            break;
                            
                        default:
                            cout << "Please enter a valid choice.\n";
                            break;
                    }
                    }
                    break;
                    
                /*operations with chequing account*/
                case 2:
                    if(_isTraceOn){
                        outfile << "Customer chose to transfer in chequing 2\n";
                    }
                    while(chequing){
                        cout <<"\n************ Jieni's Bank! *************\n" << endl;
                        cout <<"You are currently in your Chequing.\nYour balance in chequings is: " << custAcc.getCheqBalance() << "\n\n";
                        cout <<"1. Deposit\n2. Withdraw\n3. Transfer from chequing to savings\n4. Back\n ";
                        cout << "\n****************************************\n";
                        cin >> choice;
                    
                    switch(choice){
                        case 1:
                            if(_isTraceOn){
                                outfile << "Customer chose to deposit in chequing 1\n";
                            }
                            cout<< "\n************ Jieni's Bank! *************\n" << endl;
                            cout <<"Please enter amount to deposit:\n ";
                            cin >> cheq;
                            custAcc.depositCheq(cheq);
                            cout << "The amount is now deposited. Your Chequing balance is: " << custAcc.getCheqBalance() << "\n";
                            cout << "\n****************************************\n";
                            cust.writeToAccount(customer,custAcc,0);
                            break;
                            
                        case 2:
                            if(_isTraceOn){
                                outfile << "Customer chose to withdraw in chequing 2\n";
                            }
                            cout<< "\n************ Jieni's Bank! *************\n" << endl;
                            cout <<"Please enter amount to withdraw:\n ";
                            cin >> withdraw;
                            custAcc.withdrawCheq(withdraw);
                            cout << "\n****************************************\n";
                            cust.removeAmount(customer, custAcc , 1);
                            break;
                        case 3:
                            if(_isTraceOn){
                                outfile << "Customer chose to transfer in chequing 3\n";
                            }
                            cout<< "\n************ Jieni's Bank! *************\n" << endl;
                            cout <<"Please enter amount to transfer:\n ";
                            cin >> transfer;
                            custAcc.transferCheq(transfer);
                            cout << "\n****************************************\n";
                            cust.writeToAccount(customer,custAcc,1);
                            break;
                        case 4:
                            if(_isTraceOn){
                                outfile << "Customer changed accounts 4\n";
                            }
                            isChosen = false;
                            chequing = false;
                            break;
                        default:
                            cout << "Please enter a valid choice.\n";
                            break;
                    }
                    }

                    break;
                    
                /* change account */
                case 3:
                    if(_isTraceOn){
                        outfile << "Customer chose to change main account 3\n";
                    }
                    isChosen = false;
                    isAccounts = false;
                    break;
                  
                /*exit*/
                case 4:
                    if(_isTraceOn){
                        outfile << "Customer chose to exit 4\nEnd of session.\n\n";
                        outfile.close();
                        _isTraceOn = false;
                    }
                    isChosen = false;
                    isAccounts = false;
                    isCustomer = false;
                    isLoggedIn =  true;
                    isBack = false;
                    break;
                    
                default:
                    cout << "You've entered an invalid option. Please Try Again.\n";
                    break;
            }
            }           // isChosen
        }           // isAccounts
      }             // isCustomer
        
        Account account;                // declare new account to be added here
        User nCustomer;
        Account info;
        string Fname, Lname;
        
        /*Manager page*/
        while(isManager){
            while(isChosen){
                access = true;
                isChoice = true;
            cout <<"\n************ Jieni's Bank! *************\n" <<endl;
    
            cout <<"Welcome " << manager.getFname()<<  endl; // *print the user's name*
            cout <<"1. Access a customer account\n2. View all accounts within Bank\n3. Create new Customer Account\n4. Exit\n";
    
            cout << "\n****************************************\n";
            cin >> choice;
            
            switch(choice){
                case 1:
                    isChosen = false;
                    break;
                    
                case 2:
                    cust.viewAllAccounts(); 
                    isChoice = false;
                    break;
                    
                case 3:
                    cout <<"\n************ Jieni's Bank! *************\n" <<endl;
                    
                    cout <<"Welcome " << manager.getFname()<<  endl; // *print the user's name*
                    cout <<"Enter the First name of the customer: ";
                    cin >> Fname;
                    
                    cout <<"Enter the Last name of the customer: ";
                    cin >> Lname;
                    
                    cout <<"Enter an amount to deposit to Savings: ";
                    cin >> sav;
                    
                    cout <<"\nEnter an amount to deposit to Chequing: ";
                    cin >> cheq;
                    
                    nCustomer.setFname(Fname);
                    nCustomer.setLname(Lname);
                    info.depositCheq(cheq);
                    info.depositSav(sav);
                    nCustomer.addAccount(info);
                    cust.newCustomer(nCustomer);
                    cout << "\n****************************************\n";
                    isChoice = false;
                    break;
                
                case 4:
                    isManager = false;
                    isLoggedIn = true;
                    isChoice = false;
                    isBack = false;
                    isChosen = false;
                    break;
                    
                default:
                    cout << "You've entered an invalid option. Please Try Again.\n";
                    break;
            }
            } // isChosen
            
            // *open a customer's account*
            while(isChoice){
                while(isCheck){
                cout << "\n************ Jieni's Bank! *************\n"<< endl;
                cout << "Please enter their account number:\n";
                cin >> accountNum;
                cout << "Please enter their first name:\n";
                cin >> fName;
                cout << "Please enter their last name:\n";
                cin >> lName;
                cout << "\n****************************************\n";
                
                /* do validation check with if and else statements, remember to set isCustomer to true if true */
                 customer = cust.findCustomer(accountNum,fName,lName);
                if ((customer.getAccNum() == accountNum) && customer.getFname() == fName && customer.getLname() == lName){
                    isCheck = false;
                    login = 1;
                }
                else{
                    cout << "Login Unsuccessful. Please Try Again.\n";
                }
             }     // isCheck
            /*Access Customer's Account*/
            Account account1;
            while(access){
            cout <<"\n************ Jieni's Bank! *************\n" << endl;
            
            cout <<"Welcome " << manager.getFname() << "!\n"<< endl; // *print the user's name*
            cout <<"What would you like to do today?\n\n";
            cout <<"1. See Customer's Accounts\n2. Open another account\n3. Close the account\n4. Logout Customer's Account\n5. Exit\n";
            cout << "\n****************************************\n";
            cin >> choice;
            
            switch(choice){
                case 1:
                    customer.viewAllAccounts();
                    break;
                    
                case 2:
                    cheq = 0;
                    sav = 0;
                        cout <<"\n************ Jieni's Bank! *************\n" << endl;
                        
                        cout <<"Enter the amount you would like to save to Chequing: ";
                        cin >> cheq;
                        cout <<"Enter the amount you would like to save to Savings: ";
                        cin >> sav;
                        account1.depositCheq(cheq);
                        account1.depositSav(sav);
                        customer.addAccount(account1);
                    
                        cout <<"\nAccount is now created.\n";
                        cout << "\n****************************************\n";
                break;
                    
                case 3:
                    cheq = 0;
                    cout <<"\n************ Jieni's Bank! *************\n" << endl;
                    
                    cout <<"Account is removed." << endl;
                   
                    cout << "\n****************************************\n";
                    cust.deleteAnAccount(customer);
                    access = false;
                    isChoice = false;
                    isChosen = true;
                break;
                    
                case 4:
                    access = false;
                    isChoice = false;
                    isChosen = true;
                    break;
                    
                case 5:
                    access = false;
                    isManager = false;
                    isLoggedIn = true;
                    isBack = false;
                    isChoice = false;
                    break;
                    
                default:
                    cout << "You've entered an invalid option. Please Try Again.\n";
                    break;
            }
           } // access
        } //isChoice
    } //isManager
    
        /*Maintenance screen*/
        while(isMaintenance){
            cout <<"\n************ Jieni's Bank! *************\n" << endl;
            cout <<"Welcome " << maintenance.getFname() << "!\n"<< endl; // *print the user's name*
            cout <<"What would you like to do today?\n\n";
            cout <<"1. Turn On Trace\n2. Turn Off Trace\n3. Logout\n";
            cout << "\n****************************************\n";
            
            cin >> choice;
            
            switch(choice){
                case 1:
                    _isTraceOn = true;
                    cout << "\nTrace is now on. You can logout now.\n";
                    break;
                case 2:
                    _isTraceOn = false;
                    cout << "\nTrace is now off. You can logout now.\n";
                    break;
                case 3:
                    isMaintenance = false;
                    isLoggedIn = true;
                    isBack = true;
                    isChoice = false;
                    break;
                    
                default:
                    cout << "You've entered an invalid option. Please Try Again.\n";
                    break;
             }
        
        } //isMaintenance
    } //
        
    }// isBack
    
    if(isLoggedIn == true && (isMaintenance = false || isManager == false || isCustomer == false)){
    /* Logged Off Message */
    cout <<"\n************ Jieni's Bank! *************\n" <<endl;
    cout <<"Thank you for banking with Jieni.\nWe hope to serve you again soon!\n";
        cout << "\n****************************************\n" << endl;
    }
    
    return 0;
}
