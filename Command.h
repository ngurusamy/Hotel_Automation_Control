#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <iostream>

class Command 
{
	public:
		Command(){};
		virtual void execute() = 0;
		virtual ~Command(){};
};

#endif

