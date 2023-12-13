#include "Patient.h"

Patient::Patient():heartBeat( 1 + (rand() % 120)), cprCount(0), heartCondition(""){
}

void Patient::receiveShock() {

}

bool Patient::receiveCPR() {

}

int Patient::getShockStrength() const {
    return shockStrength;
}

void Patient::setShockStrength(int strength) {
    shockStrength = strength;
}

int Patient::getCPRCount() const {
    return cprCount;
}

void Patient::setCPRCount(int count) {
    cprCount = count;
}

QString Patient::getHeartCondition(){
    return heartCondition;
}

void Patient::setHeartCondition(QString h){
    heartCondition = h;
}
