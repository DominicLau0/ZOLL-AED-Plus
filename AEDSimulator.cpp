#include "AEDSimulator.h"
#include <iostream>
#include <QtDebug>

AEDSimulator::AEDSimulator() : battery_percent(100), power_switch(false), shockCount(0) {
}

AEDSimulator::~AEDSimulator() {}

bool AEDSimulator::power() {
    if (power_switch == false) {
        power_switch = true;
        return true;
    } else {
        power_switch = false;
        return false;
    }
}

bool AEDSimulator::performSelfTest() {
    if(battery_percent <= 20){
        qInfo("Unit Failed");
        qInfo("Battery is low, Change battery.\n");
        replaceBattery();
        return false;
    }
    qInfo("Unit OK.");
    return true;
}

void AEDSimulator::replaceBattery(){
    std::cout << "replacing Battery \n";
    setBatteryPercent(100);
    std::cout << "Battery replaced \n";
}

void AEDSimulator::analyzeHeartRhythm() {

}

QString AEDSimulator::evaluateCPRQuality(int compression_strength){
    if(compression_strength == 0){
        return "CONTINUE CPR";
    }else if(compression_strength < 85){
        return "PUSH HARDER";
    }else{
        return "GOOD COMPRESSIONS";
    }
}

int AEDSimulator::getBatteryPercent() {
    return battery_percent;
}

void AEDSimulator::setBatteryPercent(int Percent){
    battery_percent = Percent;
}

int AEDSimulator::getShockCount(){
    return shockCount;
}

void AEDSimulator::increaseShockCount(){
    shockCount++;
}

void AEDSimulator::setShockCount(int count){
    shockCount = count;
}
