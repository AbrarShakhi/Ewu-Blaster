#pragma once

#include <cstdlib>
#include <memory>

struct Vect {
	int x, y, z;
};


class ObjectPool {
	struct Object {
		Vect obj;
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

	Vect* borrow();
	void release(Vect* p_obj);

	size_t getCapacity() const;
	size_t howManyAllocated() const;
	size_t howManyFree() const;

private:
};