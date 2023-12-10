//
//  AEDSimulator.cpp
//  
//
//  Created by Dami on 02/12/2023.
//
#include "AEDSimulator.h"
#include <iostream>
#include <QtDebug>

AEDSimulator::AEDSimulator() : battery_percent(1 + (rand() % 105)), power_switch(false) {
}

AEDSimulator::~AEDSimulator() {}

bool AEDSimulator::power() {
    //If the device is turned off, turn on.
    if (power_switch == false) {
        power_switch = true;
        return true;

    //If the device is turned on, turn off.
    } else {
        power_switch = false;
        return false;
    }
}

bool AEDSimulator::performSelfTest() {
    //Return false if battery is low.
    if(battery_percent <= 70){
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

void AEDSimulator::analyzeHeartRhythm(Patient& patient,User& user) {
    // Simulate heart rhythm analysis
    std::cout << "Analyzing heart rhythm... \n";
    // ... (actual analysis logic)
    for(int i =0;i<=5;i++){
        if (patient.getHeartBeat()<= 59 || patient.getHeartBeat() >=101) {
            user.applyPads();
            prepareForShock(patient, user);
        }
        else
            if(patient.getShockCount()>=1 &&patient.getCPRCount()>=1) {
                provideFeedback(patient);
                evaluateCPRQuality(patient);
                break;
                return;
            }
            else if(patient.getShockCount()>=1 &&patient.getCPRCount()<=0){
                provideFeedback(patient);
                monitorPostShockCare();
                break;
            }
        // Automatically deliver shock if advised
    }
}

    int getBatteryPercent() const{ rerurn battery_percent}
    void setBatteryPercent(int Percent){
        battery_percent = Percent;
    }



void AEDSimulator::prepareForShock(Patient& patient,User& user) {
        //should depend on shockCount to adjust shockStrength
    if (patient.getShockCount() == 0) {
        patient.setShockStrength(200);
        patient.setShockCount(1);
        deliverShock(patient);

        // Update patient's heart rhythm here to show stabilization
    } else if (patient.getShockCount() > 0 && patient.getShockCount() <= 3) {
        patient.setShockStrength(360); // Joules, anywhere between 150 and 360 Joules for every shock after the first
        patient.setShockCount(patient.getShockCount() + 1);
        deliverShock(patient);
    } else if (patient.getShockCount() > 3) {
        // After 3 shocks, call CPR and update heart rhythm
        std::cout << "Patient is Dying perform CPR " ;
        user.performCPR(patient);
        analyzeHeartRhythm(patient,user);
    }

}

void AEDSimulator::deliverShock(Patient& patient) {
    std::cout << "Delivering shock with strength " << patient.getShockStrength() << " Joules...\n";
    std::cout << "Shock delivered.\n";
    patient.receiveShock(); // Call receiveShock in the Patient class
        // ... (additional logic as needed)

}

void AEDSimulator::evaluateCPRQuality(Patient& patient) {
    // Simulate CPR quality evaluation
    std::cout << "Evaluating CPR quality... \n";
    if (patient.getHeartBeat()>= 60 && patient.getHeartBeat() <=100){
         std::cout << "Patient is ok CPR worked they should make a full recovery\n";
    }
    std::cout << "Evaluation complete.\n";
}


void AEDSimulator::monitorPostShockCare() {
    // Simulate monitoring post-shock care
    std::cout << "Post shock care \n";
    std::cout << "Check if they are responsive\n ";
    std::cout << "Ask the user how they feel \n";
    std::cout << "Ensure to speak loudly \n";


    // ... (actual monitoring logic)
    std::cout << "Monitoring complete.\n";
}


void AEDSimulator::provideFeedback(Patient& patient) {
    if (patient.getHeartBeat()>= 60 && patient.getHeartBeat() <=100){
         std::cout << "Patient is ok and should make a full recovery\n ";
    }
    if (patient.getHeartBeat()<= 50 || patient.getHeartBeat() >= 101){
         std::cout << "Patient is Still in need of medical attention and should be taken to a hospital\n ";
    }
    if (patient.getHeartBeat()== 0 ){
         std::cout << "Patient is Dead ";
    }
}
