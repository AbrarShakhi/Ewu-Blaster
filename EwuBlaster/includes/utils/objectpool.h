#pragma once
#include "olcPixelGameEngine.h"
#include <vector>


template <typename T>
class objectPool {
private:
	std::vector<T*> object_pools;
	std::vector<T*> allocated; // for tracking free space 

public:
	objectPool(size_t size);
	~objectPool();

	T* borrow();
	void release(T* obj);
};