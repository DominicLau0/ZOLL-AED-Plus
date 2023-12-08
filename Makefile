objects = test_simulation.o Patient.o User.o AEDSimulator.o
CXXFLAGS = -std=c++11 -Wall -Wextra -Wunused-variable

a2: $(objects)
	g++ -o a2 $(objects) 

test_simulation.o: test_simulation.cpp
	g++ -c $(CXXFLAGS) test_simulation.cpp

AEDSimulator.o: AEDSimulator.hpp AEDSimulator.cpp
	g++ -c $(CXXFLAGS) AEDSimulator.cpp

Patient.o: Patient.h Patient.cpp
	g++ -c $(CXXFLAGS) Patient.cpp

User.o: User.h User.cpp
	g++ -c $(CXXFLAGS) User.cpp

clean:
	rm -f a2 *.o
