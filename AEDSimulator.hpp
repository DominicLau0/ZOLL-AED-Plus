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

    /*function to turn on the AED when instructed by the user*/
    bool power(bool power_switch);
// assign values to the variable for ShockStrength and shockCount based on the value from analyzeHearthRhythm and call the deliverShockFunction after
    void prepareForShock(Patient& patient,User& user);
//perform a series of self tests
    bool performSelfTest();
// take the data from the patients Heart_Beat and coem up with an analysis
    void analyzeHeartRhythm(Patient& patient, User& user);
// Give feedback on the CPR quality
    void evaluateCPRQuality(); 
    bool checkSafety();
//advice wether CPR is needed or if the patient is ok or dead
    void advisePostShockCare(); // Corrected spelling
//chekc the condiytion of the patient after receiving shock
    void monitorPostShockCare();
  //  bool pressShockButton(bool shock_Button);
    void deliverShock(Patient& patient); // Corrected parameter spelling
    void provideFeedback(); // Corrected type
    void warnForSafety();

private:
    float battery_percent; // Corrected spelling
    std::string display_message;
    std::string audio;
    bool power_switch;
    float compression_rate;
    float compression_depth;
    bool isShockAvailable;
    bool isClearedForShock; // Corrected spelling
    int ShockStrength;
    int shockCount;
    int timer;
    bool shock_Button; // Corrected missing semicolon
};



#endif // AEDSIMULATOR_H
