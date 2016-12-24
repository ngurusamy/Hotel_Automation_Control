#ifndef _CORRIDOR_H_
#define _CORRIDOR_H_
#include <iostream>
#include "constants.h"
#include "Command.h"
#include <ConcreateCommand.h>
#include "Controller.h"

class Corridor
{
	public:
		Corridor(int lights, int acs, corrType type) : noOfLights(lights), noOfACs(acs), cType(type)
		{ 
			powerConsumption = 0;
			controller = NULL;
			lightOn = NULL;
			lightOff = NULL;
			acOn = NULL;
			acOff = NULL;
		}
		
		void initializeCorridorInsturments();
		int  powerConsumptionAtPresent();
		void switchOnLights();
		void switchOnACs();
		void switchOffLights();
		void switchOffACs();
      void getStatus();

	private:
		void initializeLights();
		void initializeAirConditioner();
		int powerConsumptionByLights();
		int powerConsumptionByAC();
      void getLightsStatus();
      void getACsStatus();

	private:
		int noOfLights;
		int noOfACs;
		int powerConsumption;
		corrType cType;
		vector <Light *> lights;
		vector <AirConditioner *> airCons;

	public:
		PowerControl * controller;

		LightOnCommand *lightOn;
		LightOffCommand *lightOff;

		AirConditionerOnCommand *acOn;
		AirConditionerOffCommand *acOff;
		
};

#endif

