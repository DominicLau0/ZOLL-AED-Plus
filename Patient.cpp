//
//  Patient1.cpp
//  
//
//  Created by Dami on 02/12/2023.
//

#include "Patient.h"

Patient::Patient():heartBeat( 1 + (rand() % 105)),shockCount(0){
    
}

bool Patient::updateHeartRhythm() {
    // Simulate updating heart rhythm
    // function is called in receiveshock and randopmly updates the heartryth
    // (actual update logic)
    heartBeat = 1 + (rand() % 105);
    return (heartBeat >= 60 && heartBeat <= 100);
}

bool Patient::updateHeartBeat() {
    // Simulate updating heart rhythm
    // function is called in receiveshock and randopmly updates the heartryth
    // (actual update logic)
    heartBeat = 1 + (rand() % 200);
    return (heartBeat >= 60 && heartBeat <= 100);
}

void Patient::receiveShock() {
    // Simulate receiving shock
    //function is called by Aed in delivershock function and calls updateheartryhtm function
    updateHeartBeat();
    if(updateHeartBeat()){
        std::cout << "Patient received shock. and is ok now\n";
        std::cout << "Heart Beat is now: " << getHeartBeat() << "\n";
        return;
    }
    std::cout << "Patient received shock. and is not ok shock again\n";
    std::cout << "Heart Beat is now:  " << getHeartBeat() << "\n";

}

//most of the logic is the same as for receiveShock, only changes are in instructions displayed on console for user
// also the int retured by this function would be used by the user to chaange the compressio strength


bool Patient::receiveCPR() {
    if (updateHeartRhythm()) {
        std::cout << "Patient received CPR. and is ok now\n";
        std::cout << "Heart Beat is now: " << getHeartBeat() << "\n";
        return true;
    }
    std::cout << "Patient received CPR. and is not ok CPR again\n";
    std::cout << "Heart Beat is now:  " << getHeartBeat() << "\n";
    return false;
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


int Patient::getHeartBeat() const {
    return heartBeat;
}
