#include <iostream>
#include "Hotel.h"
#include "constants.h"

using namespace std;

Hotel::Hotel(int floors, int mainCorridors, int subCorridors, int lights, int acs)
{
	noOfFloors = floors;
	noOfMainCorridorPerFloor = mainCorridors;
	noOfSubCorridorPerFloor = subCorridors;
	noOfLighsPerCorridor = lights;
	noOfACsPerCorridor = acs;
}

void Hotel::initializeFloors()
{
	for(int i = 0 ; i < noOfFloors; i++)
	{
      floors.push_back(new floor(i + 1, noOfMainCorridorPerFloor, noOfSubCorridorPerFloor, noOfLighsPerCorridor, noOfACsPerCorridor, 0));
      floors[i]->initializeCorridors();
	}
   cout<<"Total No Of Floors : " << floors.size()<<endl;
}

void Hotel::getStatus()
{
   for(unsigned int i = 0; i < floors.size(); i++)
   {
      cout<<"Floor " << i + 1 << " Status : " << endl;
      floors[i]->getStatus();
      cout<<"------------------------------------"<<endl;
   }
}

/*void Hotel::updateStatusOnMotion()
{

}*/

void Hotel::updateSubCorrStatusOnMotion(int floorNo, int subCorrNo)
{
   if((unsigned int)(floorNo - 1) > floors.size())
   {
      cout<<"Floor " << floorNo << " does not exist" << endl;
   }
   else
   {
      floors[floorNo - 1]->setMovement(true);
      floors[floorNo - 1]->updateOnMovement(subCorrNo);
   }
}

void Hotel::getStatusPerFloor(int floorNo)
{
	floors[floorNo - 1]->getStatus();
}

int Hotel::powerConsumptionPerFloor(int floorNo)
{
   return (floors[floorNo - 1]->totalPowerConsumption());
}

void Hotel::controlPowerConsumptionOnMovement(int floorNo, int subCorrNo)
{
   PowerUnitCfg * powerUnitCfgIns = PowerUnitCfg::getPowerUnitCfgIns(POWER_UNITS_PER_LIGHT, POWER_UNITS_PER_AC);
   if(powerConsumptionPerFloor(floorNo) > powerUnitCfgIns->maxPowerPerFloor(noOfMainCorridorPerFloor, noOfSubCorridorPerFloor))
   {
      cout << "Power Consumption at Floor : " << floorNo << " is exceeded , needs to be controlled." <<endl;
      floors[floorNo - 1]->AdjustPowerConsumption(subCorrNo);
   }
   else
   {
      cout << "Power Consumption at Floor : " << floorNo << " is under control." <<endl;
   }
}
