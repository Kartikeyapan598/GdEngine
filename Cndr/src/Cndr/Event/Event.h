#pragma once

#include "Cndr/Core.h"

namespace Cndr
{

	// Event object will be a callable object and Inherit from EvnetDispatcher

	class CR_API Event
	{
		enum		// Enum to define some Event like key pressed, mousebutton pressed etc.
		{
			keypressed = 0
		};

	private:
		friend class EventDispatcher;
	};

	// EvnetDispatcher Will be called at destruction of every event via Evnet class.

	class EvnetDispatcher
	{

	};

}