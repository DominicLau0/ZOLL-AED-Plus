#ifndef PATIENT_H
#define PATIENT_H
class Patient;
#include <string>
#include <stdio.h>
#include <iostream>
#include <random>

#include "User.h"
#include <QString>

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

    QString getHeartCondition();
    void setHeartCondition(QString);

private:
    int heartBeat;
    int shockStrength;
    int cprCount;
    QString heartCondition;
};

#endif // PATIENT_H
