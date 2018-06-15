final.exe: inputValidation.o main.o menu.o space.o room.o start.o exit.o
	g++ -std=c++11 *.o -o final.exe

exit.o:exit.cpp exit.hpp
	$(makeObj) exit.cpp

room.o:room.cpp room.hpp
	$(makeObj) room.cpp

start.o:start.cpp start.hpp
	$(makeObj) start.cpp

menu.o:menu.cpp menu.hpp
	$(makeObj) menu.cpp

main.o:main.cpp
	$(makeObj) main.cpp

inputValidation.o:inputValidation.cpp inputValidation.hpp
	$(makeObj) inputValidation.cpp

space.o:space.cpp space.hpp
	$(makeObj) space.cpp

clean:
	rm *.o final.exe

zip:
	zip -D Hall_Kenneth_Final_Project.zip *.cpp *.hpp *.pdf Makefile

makeObj = g++ -std=c++11 -c
