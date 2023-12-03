//
//  Patient1.hpp
//  
//
//  Created by Dami on 02/12/2023.
//

#ifndef Patient1_hpp
#define Patient1_hpp

#include <stdio.h>

class Patient{
public:
int updateHeartRhythm();
void receiveShock();
private:
bool isResponsive;
int patientID;
}

#endif /* Patient1_hpp */
