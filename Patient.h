//
//  PATIENT_H
//  
//
//  Created by Dami on 02/12/2023.
//

#ifndef PATIENT_H
#define PATIENT_H
#include <QList>

#include <stdio.h>

class Patient{
public:
  //UPdate the heartbeat after the patient receivesshock or cpr
  int updateHeartRhythm();
  //let the patient receive shock
  void receiveShock();
  //let the patient receive CPR
  void receiveCPR();

private:
  QList<int> heartBeat;
  bool isResponsive;
  int patientID;
}

#endif // PATIENT_H
