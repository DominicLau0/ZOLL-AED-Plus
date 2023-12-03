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
#include "Power.h"
#include "Patient.h"
#include "CPRFeedbackSystem.h"
#include "User.h"
#include "SafetySystem.h"
#include "ShockDeliverySystem.h"



class AEDSimulator {
public:
    AEDSimulator(); // Constructor
    ~AEDSimulator(); // Destructor

    /*function to turn on the AED when instructed by the user*/
    bool power(bool power_switch);
// assign values to the variable for ShockStrength and shockCount based on the value from analyzeHearthRhythm and call the deliverShockFunction after
    void prepareForShock();
//perform a series of self tests
    bool performSelfTest();
// take the data from the patients Heart_Beat and coem up with an analysis
    void analyzeHeartRhythm();
// Give feedback on the CPR quality
    void evaluateCPRQuality(); 
    bool checkSafety();
//advice wether CPR is needed or if the patient is ok or dead
    void advisePostShockCare(); // Corrected spelling
//chekc the condiytion of the patient after receiving shock
    void monitorPostShockCare();
  //  bool pressShockButton(bool shock_Button);
    void deliverShock(bool shock_Button, int ShockStrength, int shockCount); // Corrected parameter spelling
    void provideFeedback(std::string display_message); // Corrected type
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
