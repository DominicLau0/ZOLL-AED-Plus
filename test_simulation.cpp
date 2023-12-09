// test_simulation.cpp
#include <iostream>

#include "AEDSimulator.hpp"


// Simple assert function for testing
void assert(bool condition, const char* message) {
    if (!condition) {
        std::cerr << "Test failed: " << message << std::endl;
    } else {
        std::cout << "Test passed: " << message << std::endl;
    }
}

int main() {
    srand(time(0));
    // Create dummy objects for testing
    Patient testPatient;
    User testUser;
    AEDSimulator testAEDSimulator;
    
    std::cout << "Patient stats \n";
    std::cout << "Shock count: " << testPatient.getShockCount() << "\n";
    std::cout << "Heartbeat: " << testPatient.getHeartBeat() << "\n\n";

    testAEDSimulator.power(true);
    testAEDSimulator.analyzeHeartRhythm(testPatient,testUser);
    // Test User's functions
    
    //assert(/* Add a condition based on your User.cpp logic */, "performCPR test");
    //std::cout << "done with cpr test\n\n";
    //assert(/* Add a condition based on your User.cpp logic */, "applyPads test");

    std::cout << testPatient.getShockCount()<<"\n";
    // Test AEDSimulator's function
    
    //assert(/* Add a condition based on your AEDSimulator.cpp logic */, "analyzeHeartRhythm test");

    // Add more test cases as needed

    return 0;
}
