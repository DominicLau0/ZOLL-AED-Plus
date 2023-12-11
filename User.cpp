//
//  User.cpp
//
//
//  Created by Dami on 02/12/2023.
//

#include "User.h"

User::User() : compressionStrength(0) {}

void User::generateCPRInstructions(Patient& patient)  {
    int compressionStrengthChange = 0;

    if (patient.getHeartBeat() < 60) {
        std::cout <<"Please apply more pressure to the chest area!\n";
        compressionStrengthChange = 1 + (rand() % 5);
    } else if (patient.getHeartBeat() > 100) {
        std::cout << "Apply less pressure and slow down compressions!\n";
        compressionStrengthChange = -1 - (rand() % 5);
    } else {
        std::cout << "Patient is fine now\n";
        compressionStrengthChange = -getCompressionStrength(); // Reset to 0
    }

    // Update compressionStrength
    setCompressionStrength(compressionStrengthChange);

    // Print the force level directly from compressionStrength
    std::cout << "Now applying a force level of " << getCompressionStrength() << "\n";
}

void User::performCPR(Patient& patient){
    std::cout << "User apply a force level of " << getCompressionStrength()<< "\n " ;
    //patient.receiveCPR();

    for(int i = 0; i<=5;i++){
        if(!(patient.receiveCPR())){
            generateCPRInstructions(patient);
            patient.updateHeartRhythm();
        }else{
            return;
            break;
        }
    }
}

void User::applyPads(){
  std::cout << "PAds applied \n";
}
int User::getCompressionStrength(){
  return compressionStrength;
}

void User::setCompressionStrength(int strength){
  compressionStrength = strength;
}
