//
//  AEDSimulator.hpp
//  
//
//  Created by Dami on 02/12/2023.
//

#ifndef AEDSimulator_hpp
#define AEDSimulator_hpp

#include <stdio.h>
#include <string>

class AEDSimulator {
public:
    /*function to turn on the AED when instructed by the user*/
    bool power(bool power_switch);
    void prepareForShock();
    bool performSelfTest();
    void analyzeHeartRhythm();
    void evaluateCPRQuality(); // Corrected spelling
    bool checkSafety();
    void advisePostShockCare(); // Corrected spelling
    void monitorPostShockCare();
    bool pressShockButton(bool shock_Button);
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



#endif /* AEDSimulator_hpp */
