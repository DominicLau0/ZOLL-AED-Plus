//
//  User.h
//  
//
//  Created by Dami on 02/12/2023.
//

#ifndef USER_H
#define USER_H
#include <string>
#include <stdio.h>
#include <iostream>
#include "Patient.h"

class User {
public:
//make new analyze heart rhytm to increase likely hood oof life
//live feedback would be gotten fronm heartbeat feedback from new analyzeheartbeat
    void performCPR(Patient& patient);
    void applyPads();
private:
    std::string userID;
    int compressionStrength;
};

#endif // USER_H
