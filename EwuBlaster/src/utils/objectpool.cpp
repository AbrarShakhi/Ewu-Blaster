// #include "utils/objectpool.h"
#include "../../includes/utils/objectpool.h"

#include <assert.h>

#include <cstdlib>
#include <iostream>
#include <vector>


ObjectPool::ObjectPool() : ObjectPool(1000) {
}

ObjectPool::ObjectPool(size_t p_capacity) : capacity(p_capacity) {
	pools = new Object[capacity];
	if (!pools) {
		capacity = 0;
		return;
	}

	for (size_t i = 0; i < capacity - 1; i++) {
		pools[i].next = &(pools[i + 1]);
	}
	pools[capacity - 1].next = nullptr;
	freeHead = pools;
	allocated = 0;
}

ObjectPool::~ObjectPool() {
	if (pools)
		delete[] pools;
}

Vect* ObjectPool::borrow() {
	if (freeHead) {
		struct Object* backup = freeHead;
		freeHead = freeHead->next;
		allocated++;
		return &(backup->obj);
	}
	return nullptr;
}

void ObjectPool::release(Vect* p_obj) {
	auto i = (uintptr_t(p_obj) - uintptr_t(pools)) / sizeof(struct Object);

	if (&(pools[i].obj) != p_obj) {
		std::cout << "ERROR: " << i << '\n';
		for (size_t j = 0; j < capacity; j++) {
			if (p_obj == &(pools[j].obj)) {
				std::cout << "matched at " << j << "\n";
			}
		}

		exit(1);
	}

	auto to_add = &(pools[i]);
	to_add->next = freeHead;
	freeHead = to_add;
	allocated--;
}

size_t ObjectPool::getCapacity() const {
	return capacity;
}
size_t ObjectPool::howManyAllocated() const {
	return allocated;
}
size_t ObjectPool::howManyFree() const {
	return capacity - allocated;
}

int main() {
	ObjectPool o;
	int N = 100;

	for (size_t n = 0; n < N; n++) {
		int rn = rand() % o.getCapacity();
		std::cout << "Round: " << rn << '\n';

		std::vector<Vect*> arr;

		for (size_t i = 0; i < rn; i++) {
			auto v = o.borrow();
			v->x = i;
			v->y = i * 2;
			v->z = i * 3;
			arr.emplace_back(v);
			std::cout << "howManyAllocated: " << o.howManyAllocated() << ". howManyFree: " << o.howManyFree() << ". ["
			          << v->x << " " << v->y << " " << v->z << "]" << '\n';
		}

		for (size_t i = 0; i < rn; i++) {
			o.release(arr[i]);
		}
	}
}
