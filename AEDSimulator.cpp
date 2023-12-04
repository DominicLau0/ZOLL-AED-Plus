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

void AEDSimulator::prepareForShock(Patient& patient) {
    analyzeHeartRhythm(patient);
    advisePostShockCare();
}

bool AEDSimulator::performSelfTest() {
    // Simulate self-test
    std::cout << "Performing self-test... ";
    // ... (actual self-test logic)
    std::cout << "Self-test complete.\n";
    return true;
}

void AEDSimulator::analyzeHeartRhythm(Patient& patient) {
    // Simulate heart rhythm analysis
    std::cout << "Analyzing heart rhythm... ";
    // ... (actual analysis logic)
    if (patient.isShockAdvised()) {

    // Placeholder logic for setting shock strength and count
        patient.setShockStrength(calculateShockStrength());
        patient.setShockCount(calculateShockCount());
        deliverShock(patient);
    }
    std::cout << "Analysis complete.\n";

    // Automatically deliver shock if advised

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
}

void AEDSimulator::provideFeedback(std::string display_message) {
    std::cout << "Feedback: " << display_message << "\n";
}

void AEDSimulator::warnForSafety() {
    std::cout << "Warning: Ensure safety precautions.\n";
}

int AEDSimulator::calculateShockStrength() {
    // Placeholder for shock strength calculation
    return 200; // Default value
}

int AEDSimulator::calculateShockCount() {
    // Placeholder for shock count calculation
    return 1; // Default value
}
