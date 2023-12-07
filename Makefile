objects = test_simulation.o Patient.o User.o AEDSimulator.o

a2: $(objects)
	g++ -o a2 $(objects) 

test_simulation.o: test_simulation.cpp
	g++ -c test_simulation.cpp 

AEDSimulator.o: AEDSimulator.hpp AEDSimulator.cpp 
	g++ -c AEDSimulator.cpp

Patient.o: Patient.h Patient.cpp 
	g++ -c Patient.cpp

User.o: User.h User.cpp 
	g++ -c User.cpp


clean:
	rm -f a2 *.o	
