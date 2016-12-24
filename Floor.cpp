#include <iostream>
#include "Floor.h"

using namespace std;

floor::floor(int fno, int MainCorr, int SubCorr, int lights, int acs, int powerConsum)
{
	floorNo = fno;
	noOfMainCorr = MainCorr;
	noOfSubCorr = SubCorr;
	noLights = lights;
	noAcs = acs;
	powerConsumption = powerConsum;
	movementOnSubCorridor = false;
}

void floor::initializeMainCorridors()
{
   cout << " No of Main Corridors : " << noOfMainCorr << endl;
	for(int i = 0; i < noOfMainCorr; i++)
	{
		//mainCorridor[i] = new Corridor(noLights, noAcs, MAIN);
		mainCorridor.push_back( new Corridor(noLights, noAcs, MAIN));
      mainCorridor[i]->initializeCorridorInsturments();
	}
}

void floor::initializeSubCorridors()
{
   cout << " No of Sub Corridors : " << noOfSubCorr << endl;
	for(int i = 0; i < noOfSubCorr; i++)
	{
		//subCorridor[i] = new Corridor(noLights, noAcs, SUB);
		subCorridor.push_back( new Corridor(noLights, noAcs, SUB));
      subCorridor[i]->initializeCorridorInsturments();
	}
}

void floor::initializeCorridors()
{
	initializeMainCorridors();
	initializeSubCorridors();
}

void floor::updateOnMovement(int subCorrNo)
{
	if(isMovement())
	{
		//controller = new PowerControl;
		/*for(int i = 0; i < noOfSubCorr; i++)
		{
			subCorridor[i]->switchOnLights();
		}*/
      if((unsigned int)(subCorrNo - 1) > subCorridor.size())
      {
         cout<<"Sub Corridor " << subCorrNo << " does not exist" << endl;
      }
      else
      {
		   subCorridor[subCorrNo - 1]->switchOnLights();
      }


	}
}
void floor::getMainCorridorStatus()
{
   for(unsigned int i = 0; i < mainCorridor.size(); i++)
   {
      cout<<"  Main Corridor " << i + 1 << " Status" << endl;
      mainCorridor[i]->getStatus();
   }

}

void floor::getSubCorridorStatus()
{
   for(unsigned int i = 0; i < subCorridor.size(); i++)
   {
      cout<<"  Sub Corridor " << i + 1 << " Status" << endl;
      subCorridor[i]->getStatus();
   }

}

void floor::getStatus()
{
   getMainCorridorStatus();
   getSubCorridorStatus();
}

int floor::powerConsumptionAtMainCorr()
{
   int powerConsumption = 0;
	for(unsigned int i = 0; i < mainCorridor.size(); i++)
	{
      powerConsumption += mainCorridor[i]->powerConsumptionAtPresent();
	}
   cout<<"powerConsumptionAtMainCorr : " << powerConsumption << endl;
   return powerConsumption;
}

int floor::powerConsumptionAtSubCorr()
{
   int powerConsumption = 0;
	for(unsigned int i = 0; i < subCorridor.size(); i++)
	{
      powerConsumption += subCorridor[i]->powerConsumptionAtPresent();
	}
   cout<<"powerConsumptionAtSubCorr : " << powerConsumption << endl;
   return powerConsumption;
}

int floor::totalPowerConsumption()
{
   return (powerConsumptionAtMainCorr() + powerConsumptionAtSubCorr());
}

void floor::AdjustPowerConsumption(int subCorrNo)
{
   PowerUnitCfg * powerUnitCfgIns = PowerUnitCfg::getPowerUnitCfgIns(POWER_UNITS_PER_LIGHT, POWER_UNITS_PER_AC);
   for(unsigned int i = 0;i < subCorridor.size(); i++)
   {
      subCorridor[i]->switchOffACs();
      if(totalPowerConsumption() <= powerUnitCfgIns->maxPowerPerFloor(noOfMainCorr, noOfSubCorr))
      {
         break;
      }
   }

}
