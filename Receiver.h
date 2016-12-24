#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include <iostream>

using namespace std;

class Light
{
	public:
		void on()
		{
			cout<<"Turn on Light : " << lightNo << endl;
			unit = POWER_UNITS_PER_LIGHT;
			status = true;
		}

		void off()
		{
			cout<<"Turn off Light : " << lightNo << endl;
			unit = 0;
			status = false;
		}

      bool isOn()
      {
         /*if(status)
            cout<<"Light is : On" <<endl;
         else
            cout<<"Light is : OFF" << endl;*/
         return status;
      }

		int getUnit()
		{
			return unit;
		}

		Light(){}
		Light(int lightNumber, int Unit): lightNo(lightNumber), unit(0){ /*status = true;*/}

	private:
		int lightNo;
		int unit;
		bool status;
};

class AirConditioner
{
	public:
		void on()
		{
			cout<<"Turn on AC : " << acNo << endl;
			unit = POWER_UNITS_PER_AC;
			status = true;
		}

		void off()
		{
			cout<<"Turn off AC : " << acNo << endl;
			unit = 0;
			status = false;
		}

      bool isOn()
      {
         /*if(status)
            cout<<"AC is : ON" << endl;
         else
            cout<<"AC is : OFF" << endl;*/
         return status;
      }

		int getUnit()
		{
			return unit;
		}

		AirConditioner(){}
		AirConditioner(int acNumber, int Unit): acNo(acNumber), unit(0){ status = true;}

	private:
		int acNo;
		int unit;
		bool status;
};
#endif
