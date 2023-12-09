//
//  AEDSimulator.cpp
//  
//
//  Created by Dami on 02/12/2023.
//
#include "AEDSimulator.hpp"

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

bool AEDSimulator::performSelfTest() {
    // Simulate self-test
    std::cout << "Performing self-test... ";
    // ... (actual self-test logic)
    if(this->battery_percent <=20){
        std::cout << "BAttery Low change/ CHarge Battery \n";
        return false;
    }

    std::cout << "Self-test complete.\n\n";
    return true;
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



