//
//  User.cpp
//  
//
//  Created by Dami on 02/12/2023.
//

#include "User.h"

void User::generateCPRInstructions(Patient& patient) const {
    if (patient.getHeartBeat() < 60) {
        std::cout << "Please apply more pressure to the chest area!\n";
        *this.setCompressionStrength( 1 + (rand() % 5));
    } else if (patient.getHeartBeat() > 100) {
        std::cout << "Apply less pressure and slow down compressions!\n";
        *this.setCompressionStrength( -1 - (rand() % 5)); //would change this to return a radnnom it betweenn -1 and -5
    } 
    std::cout << "Patient is fine now\n";
    *this.setCompressionStrength(0);
}

void User::performCPR(Patient& patient){
  std::cout << "User apply a force level of " << this->compressionStrength<< " " ;
  if(!(patient.receiveCPR())){
      generateCPRInstructions(*this);
      patient.updateHeartRhythm();
  }
    
}

void User::applyPads(){
  std::cout << "PAds applied \n";
}
int User::getCompressionStrength(){
  return compressionStrength;
}

int User::setCompressionStrength(int strength){
  compressionStrength+= strength;
}
