#ifndef _POWERUNITCFG_H_
#define _POWERUNITCFG_H_

class PowerUnitCfg
{
	public:
		static PowerUnitCfg * getPowerUnitCfgIns(int lightPower, int acPower);
      int maxPowerPerFloor(int noOfMainCorr, int noOfSubCorr);
	protected:
		PowerUnitCfg( int lightPower, int acPower);
		PowerUnitCfg(const PowerUnitCfg &){};
		void operator = (const PowerUnitCfg &){};
	private:
		static PowerUnitCfg * mPowerUnitCfg;
		int unitsForLight;
		int unitsForAc;
};

#endif
