#include <iostream>
#include "PowerUnitCfg.h"

using namespace std;

PowerUnitCfg * PowerUnitCfg::mPowerUnitCfg = 0;

PowerUnitCfg::PowerUnitCfg(int lightPower, int acPower) : unitsForLight(lightPower), unitsForAc(acPower)
{
}

PowerUnitCfg * PowerUnitCfg::getPowerUnitCfgIns(int lightPower, int acPower)
{
	if(mPowerUnitCfg == NULL)
		mPowerUnitCfg = new PowerUnitCfg(lightPower, acPower);
	
	return mPowerUnitCfg;
}

int PowerUnitCfg::maxPowerPerFloor(int noOfMainCorr, int noOfSubCorr)
{
	return ((noOfMainCorr * 15) + (noOfSubCorr * 10));
}
