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
    int updateHeartRhythm();
    void receiveShock();
    void receiveCPR();

    int getShockStrength() const;
    void setShockStrength(int strength);

    int getShockCount() const;
    void setShockCount(int count);

    bool isShockAdvised() const;

private:
    int heartBeat;
    bool isResponsive;
    int patientID;
    int shockStrength;
    int shockCount;
};

#endif // PATIENT_H
