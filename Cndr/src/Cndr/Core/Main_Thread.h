#pragma once

#include "Cndr/Interface/Thread.h"

int main(int argc, char** argv);

namespace Cndr
{

	class CR_API Main_Thread : public Thread
	{
	protected :
		static Main_Thread* main_process;
		friend int ::main(int argc, char** argv);
	};


}