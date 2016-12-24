#ifndef _CONCREATECOMMAND_H_
#define _CONCREATECOMMAND_H_

#include <iostream>
#include <Receiver.h>
#include <Command.h>

using namespace std;

class LightOnCommand : public Command
{
	public:
		LightOnCommand(Light * light) : mlight(light){}
		~LightOnCommand() {delete mlight;}
		void execute()
		{
			mlight->on();
		}
	private:
		Light * mlight; 
};

class LightOffCommand : public Command
{
	public:
		LightOffCommand(Light * light) : mlight(light){}
		~LightOffCommand() { delete mlight;}
		void execute()
		{
			mlight->off();
		}
	private:
		Light * mlight; 
};

class AirConditionerOnCommand : public Command
{
	public:
		AirConditionerOnCommand(AirConditioner * ac) : mAc(ac){}
		~AirConditionerOnCommand(){ delete mAc;}
		void execute()
		{
			mAc->on();
		}
	private:
		AirConditioner * mAc; 
};

class AirConditionerOffCommand : public Command
{
	public:
		AirConditionerOffCommand(AirConditioner * ac) : mAc(ac){}
		~AirConditionerOffCommand(){ delete mAc;}
		void execute()
		{
			mAc->off();
		}
	private:
		AirConditioner * mAc; 
};

#endif
