#pragma once

#include <cstdlib>
#include <memory>

template <typename T>
class ObjectPool {
	struct Object {
		T obj;
		struct Object* next;
	};

public:
private:
	size_t capacity;
	size_t allocated;
	struct Object* pools = nullptr;
	struct Object* freeHead = nullptr;

public:
	ObjectPool();
	ObjectPool(size_t p_capacity);
	~ObjectPool();

	T* borrow();
	void release(T* p_obj);

	size_t getCapacity() const;
	size_t howManyAllocated() const;
	size_t howManyFree() const;

private:
};