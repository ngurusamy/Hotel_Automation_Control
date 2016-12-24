#include <iostream>
#include "Corridor.h"


void Corridor::initializeCorridorInsturments()
{
	initializeLights();
	initializeAirConditioner();
}

void Corridor::initializeLights()
{
	for(int i = 0; i < noOfLights ; i++)
	{
		lights.push_back( new Light( i + 1, POWER_UNITS_PER_LIGHT));
		
		if(cType == MAIN)
		{
			lights[i]->on();
			powerConsumption += POWER_UNITS_PER_LIGHT;
		}
	}
}

void Corridor::initializeAirConditioner()
{
	for(int i = 0; i < noOfACs ; i++)
	{
		airCons.push_back( new AirConditioner( i + 1, POWER_UNITS_PER_AC));
      airCons[i]->on();
		powerConsumption += POWER_UNITS_PER_AC;
	}
}

int Corridor::powerConsumptionAtPresent()
{
   return (powerConsumptionByLights() + powerConsumptionByAC());
}

int Corridor::powerConsumptionByLights()
{
   int powerConsumed = 0;
   for(unsigned int i = 0; i < lights.size(); i++)
   {
      powerConsumed += lights[i]->getUnit();
   }
   cout<<" Power Consumed By Lights : " << powerConsumed << endl;
   return powerConsumed;

}

int Corridor::powerConsumptionByAC()
{
   int powerConsumed = 0;
   for(unsigned int i = 0; i < airCons.size(); i++)
   {
      powerConsumed += airCons[i]->getUnit();
   }
   cout<<" Power Consumed By ACs : " << powerConsumed << endl;
   return powerConsumed;

}

void Corridor::switchOnLights()
{
   cout<<"Entering switch On Lights" << endl;
	controller = new PowerControl();
	for(int i = 0; i < noOfLights ; i++)
	{
		lightOn = new LightOnCommand(lights[i]);
		controller->setCommand(lightOn);
		controller->execute();
		powerConsumption += POWER_UNITS_PER_LIGHT;
	}
}

void Corridor::switchOffLights()
{
	controller = new PowerControl;
	for(int i = 0; i < noOfLights ; i++)
	{
		lightOff = new LightOffCommand(lights[i]);;
		controller->setCommand(lightOff);
		controller->execute();
		powerConsumption -= POWER_UNITS_PER_LIGHT;
	}
}

void Corridor::switchOnACs()
{
	controller = new PowerControl;
	for(int i = 0; i < noOfACs ; i++)
	{
		acOn = new AirConditionerOnCommand(airCons[i]);
		controller->setCommand(acOn);
		controller->execute();
		powerConsumption += POWER_UNITS_PER_AC;
	}
}

void Corridor::switchOffACs()
{
	controller = new PowerControl;
	for(int i = 0; i < noOfACs ; i++)
	{
		acOff = new AirConditionerOffCommand(airCons[i]);
		controller->setCommand(acOff);
		controller->execute();
		powerConsumption -= POWER_UNITS_PER_AC;
	}
}

void Corridor::getLightsStatus()
{
	for(unsigned int i = 0; i < lights.size() ; i++)
	{
      if(lights[i]->isOn())
      {
         cout<<"     Light " << i + 1 << " is ON" <<endl;
      }
      else
      {
         cout<<"     Light " << i + 1 << " is OFF" <<endl;
      }
	}

}

void Corridor::getACsStatus()
{
	for(unsigned int i = 0; i < airCons.size() ; i++)
	{
      if(airCons[i]->isOn())
      {
         cout<<"     AC " << i + 1 << " is ON" <<endl;
      }
      else
      {
         cout<<"     AC " << i + 1 << " is OFF" <<endl;
      }
	}

}

void Corridor::getStatus()
{
   getLightsStatus();
   getACsStatus();
}
