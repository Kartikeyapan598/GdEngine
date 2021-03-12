#pragma once
#include "Cndr/Core.h"
#include "Event.h"

namespace Cndr
{


	class CR_API EventSystem
	{
	private :
		// Singleton Class object to deny assess to Constructor and Destructor
		EventSystem();
		~EventSystem();
		EventSystem(const EventSystem& rhs) {};
		EventSystem& operator=(const EventSystem& rhs) {};
	};


}