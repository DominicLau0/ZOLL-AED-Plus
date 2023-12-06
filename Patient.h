//
//  PATIENT_H
//  
//
//  Created by Dami on 02/12/2023.
//

#ifndef PATIENT_H
#define PATIENT_H



class Patient {
public:
    bool updateHeartRhythm();
    void receiveShock();
    void receiveCPR();

    int getShockStrength() const;
    void setShockStrength(int strength);

    int getShockCount() const;
    void setShockCount(int count);

    bool isShockAdvised() const;
    int getHeartBeat() const;
    int generateCPRInstructions() const;

private:
    int heartBeat;
    bool isResponsive;
    int patientID;
    int shockStrength;
    int shockCount;
};

#endif // PATIENT_H
