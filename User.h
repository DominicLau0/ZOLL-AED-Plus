#ifndef USER_H
#define USER_H

class Patient;
#include <string>
#include <stdio.h>
#include <iostream>
#include <random>
#include "Patient.h"


class User {
public:
//make new analyze heart rhytm to increase likely hood oof life
//live feedback would be gotten fronm heartbeat feedback from new analyzeheartbeat
    User();
    void performCPR(Patient& patient);
    int getCompressionStrength();
    void setCompressionStrength(int strength);
    void generateCPRInstructions(Patient& patient);

    bool getPadsApplied();
    void setPadsApplied(bool);

private:
    std::string userID;
    int compressionStrength;
    bool padsApplied;
};

#endif // USER_H
