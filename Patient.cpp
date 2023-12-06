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
        return;
    }
    std::cout << "Patient received shock. and is not ok shock again\n";
    // ... (additional logic as needed)
}

//most of the logic is the same as for receiveShock, only changes are in instructions displayed on console for user
// also the int retured by this function would be used by the user to chaange the compressio strength
int Patient::generateCPRInstructions() const {
    if (heartBeat < 60) {
        std::cout << "Please apply more pressure to the chest area!\n";
        return 1 + (rand() % 5);
    } else if (heartBeat > 100) {
        std::cout << "Apply less pressure and slow down compressions!\n";
        return -5; //would change this to return a radnnom it betweenn -1 and -5
    }
}

void Patient::receiveCPR() {
    if (updateHeartRhythm()) {
        std::cout << "Patient received CPR.\n";
        std::cout << "CPR successful\n";
        return;
    }
    generateCPRInstructions();
    updateHeartRhythm();
}
    
    //std::cout << "Patient received CPR.\n";
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
