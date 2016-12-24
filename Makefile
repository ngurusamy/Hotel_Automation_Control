# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

#CXX = /usr/sfw/bin/g++
CXX = g++
CXXFLAGS = -Wall -g
INC = -I./

# ****************************************************
# Targets needed to bring the executable up to date

#main: Main.o PowerUnitCfg.o Hotel.o Floor.o Corridor.o ConcreateCommand.o PowerUnits.o PowerUnitCfg.o constants.o Controller.o
Main: Main.o PowerUnitCfg.o Hotel.o Floor.o Corridor.o ConcreateCommand.o PowerUnits.o PowerUnitCfg.o constants.o Controller.o
	$(CXX) $(CXXFLAGS) $(INC) -o Main Main.o PowerUnitCfg.o Hotel.o Floor.o Corridor.o

# The main.o target can be written more simply

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c Main.cpp 

#PowerUnitCfg.o: PowerUnitCfg.h PowerUnitCfg.cpp

Hotel.o: Hotel.h Hotel.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c Hotel.cpp

Floor.o: Floor.h Floor.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c Floor.cpp

Corridor.o: Corridor.h Corridor.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c Corridor.cpp

ConcreateCommand.o: ConcreateCommand.h

PowerUnits.o: PowerUnits.h

PowerUnitCfg.o: PowerUnitCfg.h PowerUnitCfg.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c PowerUnitCfg.cpp

constants.o: constants.h

Controller.o: Controller.h

clean:
	\rm *.o Main
