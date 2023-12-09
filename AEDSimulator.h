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
    AEDSimulator();
    ~AEDSimulator();


    bool power();
    void prepareForShock(Patient& patient,User& user);
    bool performSelfTest();
    void analyzeHeartRhythm(Patient& patient, User& user);
    void evaluateCPRQuality(Patient& patient);
    void monitorPostShockCare();
    void deliverShock(Patient& patient);
    void provideFeedback(Patient& patient);

    int getBatteryPercent() const;
    void setBatteryPercent(int Percent);



private:
    float battery_percent;
    std::string display_message;
    std::string audio;
    bool power_switch;
};



#endif // AEDSIMULATOR_H
