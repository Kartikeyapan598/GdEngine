#pragma once

#include "Cndr/Core.h"
#include <string>
#define EVENTID std::string
namespace Cndr
{
	// Event object will be a callable object and Inherit from EvnetDispatcher

	class CR_API Event
	{
	private : // Members
		EVENTID eventId;
		void* parameter;

	public :
		Event(EVENTID eventID, void* param = NULL)
			:eventId(eventID), parameter(param)
		{

		}

		~Event() {}

		inline EVENTID EvnetId() const { return eventId; }
		inline void* Ret_Parameter() { return parameter; }

	};

	// EvnetDispatcher Will be called at destruction of every event via Evnet class.

	class EvnetDispatcher
	{

	};

}