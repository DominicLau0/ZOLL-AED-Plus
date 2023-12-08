objects = test_simulation.o Patient.o User.o AEDSimulator.o
CXXFLAGS = -std=c++11 -Wall -Wextra -Wunused-variable

a2: $(objects)
	g++ -o a2 $(objects) 

test_simulation.o: test_simulation.cc
	g++ -c $(CXXFLAGS) test_simulation.cc 

AEDSimulator.o: AEDSimulator.h AEDSimulator.cc 
	g++ -c $(CXXFLAGS) AEDSimulator.cc

Patient.o: Patient.h Patient.cc 
	g++ -c $(CXXFLAGS) Patient.cc

User.o: User.h User.cc 
	g++ -c $(CXXFLAGS) User.cc

clean:
	rm -f a2 *.o
