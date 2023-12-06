//
//  User.cpp
//  
//
//  Created by Dami on 02/12/2023.
//

#include "User.hpp"


void User::performCPR(Patient& patient){
  patient.receiveCPR();
}

void User::applyPads(){
  std::cout << "PAds applied \n";
}
