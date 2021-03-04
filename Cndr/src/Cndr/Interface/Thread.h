#pragma once

#include "Cndr/Core.h"

#ifndef THREAD_H
#define THREAD_H

#include <thread>
#include <atomic>
#include <memory>

namespace Cndr
{
	enum class Priority
	{
		Lowest = 1,
		Low,
		Normal,
		High,
		Highest
	};

	class Thread
	{
	public :
		virtual ~Thread();

		Thread();
		Thread(const Thread& original) = delete; // Copy constructor
		Thread(Thread&& original) = delete; // Move Constructor
		Thread& operator=(Thread&& rhs) noexcept;  // Move Assignment
		Thread& operator=(const Thread& rhs) = delete; // Copy Assignment

		virtual void Priority_change(Thread& thread);

		virtual void Begin();
		virtual void Join();
		virtual void Join_on_ID(Thread& id);

	private :
		uint64_t ID;
		Priority level = Priority::Normal; 

	};
}

#endif // !THREAD_H