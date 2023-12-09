//
// AEDSimulator.h
//  
//
//  Created by Dami on 02/12/2023.
//

#ifndef AEDSIMULATOR_H
#define AEDSIMULATOR_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "Patient.h"
#include "User.h"


class AEDSimulator {
public:
    AEDSimulator(); // Constructor
    ~AEDSimulator(); // Destructor


    bool power(bool power_switch);
    void prepareForShock(Patient& patient,User& user);
    bool performSelfTest();
    void analyzeHeartRhythm(Patient& patient, User& user);
    void evaluateCPRQuality(Patient& patient);
    void monitorPostShockCare();
    void deliverShock(Patient& patient);
    void provideFeedback(Patient& patient); // Corrected type


private:
    float battery_percent; // Corrected spelling
    std::string display_message;
    std::string audio;
    bool power_switch;
};



#endif // AEDSIMULATOR_H
