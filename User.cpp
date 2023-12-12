#include "User.h"

User::User() : compressionStrength(0), padsApplied(false) {}

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

bool User::getPadsApplied(){
    return padsApplied;
}

void User::setPadsApplied(bool p){
    padsApplied = p;
}


int User::getCompressionStrength(){
  return compressionStrength;
}

void User::setCompressionStrength(int strength){
  compressionStrength = strength;
}
