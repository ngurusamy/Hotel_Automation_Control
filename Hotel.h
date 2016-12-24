#ifndef _HOTEL_H_
#define _HOTEL_H_

#include <iostream>
#include <Floor.h>
#include "PowerUnitCfg.h"

using namespace std;

class Hotel
{
	public:
		void getStatus();
		void getStatusPerFloor(int floorNo);
		//void updateStatusOnMotion();
		void updateSubCorrStatusOnMotion(int floorNo, int subCorrNo);
		void controlPowerConsumptionOnMovement(int floorNo, int subCorrNo);
		Hotel(int floors, int mainCorridors, int subCorridors, int lights, int acs);
		void initializeFloors();
		int powerConsumptionPerFloor(int floorNo);
	private:

		vector <floor *> floors;
		int noOfFloors;
		int noOfMainCorridorPerFloor;
		int noOfSubCorridorPerFloor;
		int noOfLighsPerCorridor;
		int noOfACsPerCorridor;


};
#endif
