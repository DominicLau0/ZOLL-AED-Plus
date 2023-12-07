objects = main.o TestView.o TestControl.o Editor.o VideoRepo.o VideoArray.o Video.o SceneArray.o Scene.o Date.o

a2: $(objects)
	g++ -o a2 $(objects) 

main.o: main.cc
	g++ -c main.cc 

TestView.o: TestView.h TestView.cc 
	g++ -c TestView.cc

TestControl.o: TestControl.h TestControl.cc 
	g++ -c TestControl.cc

Editor.o: Editor.h Editor.cc 
	g++ -c Editor.cc

VideoRepo.o: VideoRepo.h VideoRepo.cc
	g++ -c VideoRepo.cc

VideoArray.o: VideoArray.h VideoArray.cc
	g++ -c VideoArray.cc

Video.o: Video.cc Video.h
	g++ -c Video.cc

SceneArray.o: SceneArray.cc SceneArray.h
	g++ -c SceneArray.cc
	
Scene.o: Scene.cc Scene.h 
	g++ -c Scene.cc

Date.o: Date.cc Date.h 
	g++ -c Date.cc

clean:
	rm -f a2 *.o	