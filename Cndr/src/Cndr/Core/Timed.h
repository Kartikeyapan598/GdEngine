#pragma once

#include <time.h>
#include "Core.h"

class CR_API Timer
{
public :
	Timer(float time = 0.0f)
		:m_time(time)
	{

	}

	operator float() const { return m_time; }
	float GetSeconds() const { return m_time; }
	float GetMilliseconds() const { return m_time * 1000.0f; }
private :

	float m_time;

};