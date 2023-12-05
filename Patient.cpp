//
//  Patient1.cpp
//  
//
//  Created by Dami on 02/12/2023.
//

#include "Patient.h"
#include <iostream>

int Patient::updateHeartRhythm() {
    // Simulate updating heart rhythm
    // function is called in receiveshock and randopmly updates the heartryth
    // (actual update logic)
    
    return 0; 
}

void Patient::receiveShock() {
    // Simulate receiving shock
    //function is called by Aed in delivershock function and calls updateheartryhtm function
    updateHeartRhythm();
    std::cout << "Patient received shock.\n";
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

bool Patient::isShockAdvised() const {
    // Placeholder for shock advice logic
    return true; // Default to true for testing
}
