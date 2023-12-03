//
//  Patient1.hpp
//  
//
//  Created by Dami on 02/12/2023.
//

#ifndef Patient1_hpp
#define Patient1_hpp

#include <stdio.h>

class Patient{
public:
//UPdate the heartbeat after the patient receivesshock or cpr
int updateHeartRhythm();
//let the patient receive shock
void receiveShock();
//let the patient receive CPR
void receiveCPR();

private:
bool isResponsive;
int patientID;
}

#endif /* Patient1_hpp */
