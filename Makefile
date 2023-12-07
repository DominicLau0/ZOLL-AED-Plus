objects = test_simulation.o Patient.o User.o AEDSimulator.o

a2: $(objects)
	g++ -o a2 $(objects) 

test_simulation.o: test_simulation.cc
	g++ -c test_simulation.cc 

AEDSimulator.o: AEDSimulator.h AEDSimulator.cc 
	g++ -c AEDSimulator.cc

Patient.o: Patient.h Patient.cc 
	g++ -c Patient.cc

User.o: User.h User.cc 
	g++ -c User.cc


clean:
	rm -f a2 *.o	
