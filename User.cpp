//
//  User.cpp
//  
//
//  Created by Dami on 02/12/2023.
//

#include "User.h"


void User::performCPR(Patient& patient){
  std::cout << "User apply a force level of " << this->compressionStrength<< " " ;
  patient.receiveCPR();
}

void User::applyPads(){
  std::cout << "PAds applied \n";
}
int User::getCompressionStrength(){
  return compressionStrength;
}

int User::setCompressionStrength(int strength){
      strength = compressionStrength;
}
