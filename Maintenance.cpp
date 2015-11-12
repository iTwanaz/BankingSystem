//
//  Maintenance.cpp
//  BankingSystem
//
//  Created by Jieni Hou on 2015-10-09.
//  CS3307 A1
//  Copyright (c) 2015 Jieni Hou. All rights reserved.
//

#include "Maintenance.h"

/******************************************************************************************************
    Maintenance Constructor
 ******************************************************************************************************/
Maintenance::Maintenance(){
}

/******************************************************************************************************
   Maintenance Deconstructor
 ******************************************************************************************************/
Maintenance::~Maintenance(){
}

/******************************************************************************************************
loadMaintenanceBase Constructor
 ******************************************************************************************************/
void Maintenance::loadMaintenanceBase(){
    User main;
    string str;
    string token;
    vector<string> list;
    ifstream infile;
    
    infile.open("maintenance.txt");
    
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
        
        //set maintenance objects
        main.setAccNum(stoi(list[0]));
        main.setFname(list[1]);
        main.setLname(list[2]);
        
        // put the set maint into the vector
        maintenances.push_back(main);
        list.clear();
    }
    
    infile.close();
}

/******************************************************************************************************
    printTime prints the current time of the trace
 ******************************************************************************************************/
    string Maintenance::printTime(){
    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;
}

/******************************************************************************************************
 findMaintenance finds maintenance through verification, and if not found, returns an empty maintenance object
 ******************************************************************************************************/
User Maintenance::findMaintenance(int accNum, string fName, string lName){
    User maintenance;
    bool isFound = false;
    loadMaintenanceBase();
    // loop through customer base to find for match
    for(int i = 0; i < maintenances.size(); i++){
        if(maintenances[i].getAccNum() == accNum && maintenances[i].getFname() == fName && maintenances[i].getLname() == lName){
            isFound = true;
            maintenance = maintenances[i];
        }
    }
    
    // when its found, return the maintenance's information
    if(isFound){
        return maintenance;
    }
    else{
        maintenance.setAccNum(-1);
        return maintenance;
    }
}
