#pragma once
#include <stdlib.h>
inline void* operator new(size_t size)
{
	std::cout << "Memory Allocated!"<<" size -"<<size<<"\n";
	return malloc(size);
}

inline void operator delete(void* ptr)
{
	std::cout << "Memory Freed!" << "\n";
	free(ptr);
}