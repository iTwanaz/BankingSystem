//
//  Managers.cpp
//  BankingSystem
//
//  Created by Jieni Hou on 2015-10-09.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#include "Managers.h"

/******************************************************************************************************
    Managers Constructor
 ******************************************************************************************************/
Managers::Managers(){
}

/******************************************************************************************************
    Managers Deconstructor
 ******************************************************************************************************/
Managers::~Managers(){
}

/******************************************************************************************************
    loadManagerBase loads the manager base from managers.txt
 ******************************************************************************************************/
void Managers::loadManagerBase(){
    User man;
    string str;
    string token;
    vector<string> list;
    ifstream infile;
    
    infile.open("managers.txt");
    
    // check for error
    if (infile.fail()){
        cerr << "Error loading file. Exiting Program." << endl;
        exit(1);
    }
    
    // load string
    while(getline(infile,str)){
        istringstream iss(str);
        //separate string and put into vector
        while(getline(iss,token,',')){
            list.push_back(token);
        }
        
        //set customer objects
        man.setAccNum(stoi(list[0]));
        man.setFname(list[1]);
        man.setLname(list[2]);
        
        // put the set manager into the vector
        managers.push_back(man);
        list.clear();
    }
    
    infile.close();
}

/******************************************************************************************************
    findManager finds a manager through verification, and if not found, returns an empty customer object
 ******************************************************************************************************/
User Managers::findManager(int accNum, string fName, string lName){
    User manager;
    bool found = false;
    loadManagerBase();
    // loop through customer base to find for match
    for(int i = 0; i < managers.size(); i++){
        if(managers[i].getAccNum() == accNum && managers[i].getFname() == fName && managers[i].getLname() == lName){
            found = true;
            manager = managers[i];
        }
    }
    
    // when its found, return the manager's information
    if(found){
        return manager;
    }
    else{
        manager.setAccNum(-1);
        return manager;
    }
}