//
//  PATIENT_H
//  
//
//  Created by Dami on 02/12/2023.
//

#ifndef PATIENT_H
#define PATIENT_H
class Patient;
#include <string>
#include <stdio.h>
#include <iostream>
#include <random>

#include "User.h"

class Patient {
public:
    Patient();
    bool updateHeartRhythm();
    bool updateHeartBeat();
    void receiveShock();
    bool receiveCPR();

    int getShockStrength() const;
    void setShockStrength(int strength);

    int getShockCount() const;
    void setShockCount(int count);
    
    int getCPRCount() const;
    void setCPRCount(int count);

    int getHeartBeat() const;
    

private:
    int heartBeat;
    int shockStrength;
    int shockCount;
    int cprCount;
};

#endif // PATIENT_H
