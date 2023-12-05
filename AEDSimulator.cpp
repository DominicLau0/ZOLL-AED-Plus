//
//  AEDSimulator.cpp
//  
//
//  Created by Dami on 02/12/2023.
//
#include "AEDSimulator.h"
#include <iostream>

AEDSimulator::AEDSimulator() : battery_percent(100), power_switch(false) {}

AEDSimulator::~AEDSimulator() {}

bool AEDSimulator::power(bool power_switch) {
    if (power_switch) {
        std::cout << "AED is powered on.\n";
        performSelfTest();
        this->power_switch = true;
        return true;
    } else {
        std::cout << "AED is powered off.\n";
        this->power_switch = false;
        return false;
    }
}

void AEDSimulator::analyzeHeartRhythm(Patient& patient) {
    // Simulate heart rhythm analysis
    std::cout << "Analyzing heart rhythm... ";
    // ... (actual analysis logic)
    if (patient.getHeartBeat()<= 59 || patient.getHeartBeat() >=101) {
    // Placeholder logic for setting shock strength and count
        deliverShock(patient);
    }
    std::cout << "Analysis complete.\n";

    // Automatically deliver shock if advised

}


void AEDSimulator::prepareForShock(Patient& patient,User& user) {
        //should depend on shockCount to adjust shockStrength
    user.applypads();
    if (patient.getShockCount() == 0) {
        patient.setShockStrength(200); // Joules, anywhere between 120 and 200 Joules
        patient.setShockCount(1);
        // Update patient's heart rhythm here to show stabilization
    } else if (patient.getShockCount() > 0 && patient.getShockCount() <= 3) {
        patient.setShockStrength(360); // Joules, anywhere between 150 and 360 Joules for every shock after the first
        patient.setShockCount(patient.getShockCount() + 1);
    } else if (patient.getShockCount() > 3) {
        // After 3 shocks, call CPR and update heart rhythm
        user.performCPR();
        patient.receiveCPR();
        analyzeHeartRhythm(patient);
    }

}

bool AEDSimulator::performSelfTest() {
    // Simulate self-test
    std::cout << "Performing self-test... ";
    // ... (actual self-test logic)
    std::cout << "Self-test complete.\n";
    return true;
}



void AEDSimulator::evaluateCPRQuality() {
    // Simulate CPR quality evaluation
    std::cout << "Evaluating CPR quality... ";
    // ... (actual evaluation logic)
    std::cout << "Evaluation complete.\n";
}

bool AEDSimulator::checkSafety() {
    // Simulate safety check
    std::cout << "Checking safety... ";
    // ... (actual safety check logic)
    std::cout << "Safety check complete.\n";
    return true; // Placeholder for safety check success
}

void AEDSimulator::advisePostShockCare() {
    // Simulate advice for post-shock care
    std::cout << "Advising post-shock care... ";
    // ... (actual advice logic)
    std::cout << "Advice complete.\n";
}

void AEDSimulator::monitorPostShockCare() {
    // Simulate monitoring post-shock care
    std::cout << "Monitoring post-shock care... ";
    // ... (actual monitoring logic)
    std::cout << "Monitoring complete.\n";
}

void AEDSimulator::deliverShock(Patient& patient) {
    if (checkSafety()) {
        std::cout << "Delivering shock with strength " << patient.getShockStrength() << " Joules...\n";
        patient.receiveShock(); // Call receiveShock in the Patient class
        // ... (additional logic as needed)
        std::cout << "Shock delivered.\n";
    } else {
        std::cout << "Unable to deliver shock.\n";
    }
    //delivers shock then calls update heartryhtm then calls analyze after 
    //after 3 shocks should stop shocking and move to cpr
}

void AEDSimulator::provideFeedback(std::string display_message) {
    std::cout << "Feedback: " << display_message << "\n";
}

void AEDSimulator::warnForSafety() {
    std::cout << "Warning: Ensure safety precautions.\n";
}

