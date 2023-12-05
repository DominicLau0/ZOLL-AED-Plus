//
//  Patient1.cpp
//  
//
//  Created by Dami on 02/12/2023.
//

#include "Patient.h"
#include <iostream>

bool Patient::updateHeartRhythm() {
    // Simulate updating heart rhythm
    // function is called in receiveshock and randopmly updates the heartryth
    // (actual update logic)
    heartBeat = 1 + (rand() % 120);
    if(heartBeat>=60 && heartBeat<=100){
        return true; }
    else {return false;}
}

void Patient::receiveShock() {
    // Simulate receiving shock
    //function is called by Aed in delivershock function and calls updateheartryhtm function
    if(updateHeartRhythm()){
        std::cout << "Patient received shock. and is ok now\n";   
    }
    std::cout << "Patient received shock. and is not ok shock again\n";
    // ... (additional logic as needed)
}

void Patient::receiveCPR() {
    // Simulate receiving CPR
    // function is called by patient in perfomrcpr function and calls updateheartryhtm function
    std::cout << "Patient received CPR.\n";
    // ... (additional logic as needed)
}

int Patient::getShockStrength() const {
    return shockStrength;
}

void Patient::setShockStrength(int strength) {
    shockStrength = strength;
}

int Patient::getShockCount() const {
    return shockCount;
}

void Patient::setShockCount(int count) {
    shockCount = count;
}

int Patient::getShockCount() const {
    return shockCount;
}

int Patient::getHeartBeat() const {
    return heartBeat;
}
