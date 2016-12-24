#ifndef _POWERCONTROLER_H_
#define _POWERCONTROLER_H_

#include <vector>
#include <Command.h>
#include "constants.h"

class PowerControl 
{
public:

	//PowerControl() : mOnCommand(MaxCommand), mOffCommand(MaxCommand) 
	PowerControl() 
	{
		/*for(int i = 0; i < 5; i++) 
		{
			mOffCommand[i] = NULL;
			mOnCommand[i] = NULL;
		}*/
	}
	/*void setCommand(electricalEquipment id, Command *onCmd, Command *offCmd) 
	{
		mOnCommand[id] = onCmd;
		mOffCommand[id] = offCmd;
	}*/

	void setCommand(Command *Cmd) 
	{
		mCmd = Cmd;
	}

	void onCommand(electricalEquipments id) 
	{
		mOnCommand[id]->execute();
	}
	
	void offCommand(electricalEquipments id)
	{
		mOffCommand[id]->execute();
	} 

	void execute()
	{
		mCmd->execute();
	}

private:
	vector <Command *> mOnCommand;
	vector <Command *> mOffCommand;
	Command * mCmd;
};

#endif
