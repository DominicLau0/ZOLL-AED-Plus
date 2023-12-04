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
    // (actual update logic)
    return 0; 
}

void Patient::receiveShock() {
    // Simulate receiving shock
    std::cout << "Patient received shock.\n";
    // ... (additional logic as needed)
}

void Patient::receiveCPR() {
    // Simulate receiving CPR
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
