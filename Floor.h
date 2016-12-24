#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include <Corridor.h>
#include <ConcreateCommand.h>
#include "constants.h"
#include "Controller.h"
#include "PowerUnitCfg.h"

using namespace std;

class floor
{

	private:
		vector <Corridor *> mainCorridor;
		vector <Corridor *> subCorridor;
		int floorNo;
		int noOfMainCorr;
		int noOfSubCorr;
		int noLights;
		int noAcs;
		int powerConsumption;
		bool movementOnSubCorridor;
	public:


		floor(int fno, int noOfMainCorr, int noOfSubCorr, int lights, int acs, int powerConsum);
		~floor(){};
		vector <Corridor *> getMainCorridorVec()
		{
			return mainCorridor;
		}

		vector <Corridor *> getSubCorridorVec()
		{
			return subCorridor;
		}

		int getPowerConsumed();
		void setPowerConsumded(int val);
		bool checkPowerConsumption();
		void AdjustPowerConsumption(int subCorrNo);
		bool isMovement(){return movementOnSubCorridor;}
		void setMovement(bool move) { movementOnSubCorridor = move;}
		void updateOnMovement(int subCorrNo);
      void getStatus();
      int totalPowerConsumption();

		void initializeCorridors();

		int maxPower()
		{
         PowerUnitCfg * powerUnitCfg = PowerUnitCfg::getPowerUnitCfgIns(POWER_UNITS_PER_LIGHT, POWER_UNITS_PER_AC);
			//return (mainCorridor.size() * 15 + subCorridor.size() * 10);
         return (powerUnitCfg->maxPowerPerFloor(mainCorridor.size(), subCorridor.size()));
		}

	private:
		void initializeMainCorridors();
		void initializeSubCorridors();
      void getMainCorridorStatus();
      void getSubCorridorStatus();
      int powerConsumptionAtMainCorr();
      int powerConsumptionAtSubCorr();



};

#endif
