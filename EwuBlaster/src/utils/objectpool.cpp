#include "utils/objectpool.h"

template <typename T>
ObjectPool<T>::ObjectPool() : ObjectPool(1000) {
}

template <typename T>
ObjectPool<T>::ObjectPool(size_t p_capacity) : capacity(p_capacity) {
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

template <typename T>
ObjectPool<T>::~ObjectPool() {
	if (pools)
		delete[] pools;
}

template <typename T>
T* ObjectPool<T>::borrow() {
	if (freeHead) {
		struct Object* backup = freeHead;
		freeHead = freeHead->next;
		allocated++;
		return &(backup->obj);
	}
	return nullptr;
}

template <typename T>
void ObjectPool<T>::release(T* p_obj) {
	auto i = (uintptr_t(p_obj) - uintptr_t(pools)) / sizeof(struct Object);

	auto to_add = &(pools[i]);
	to_add->next = freeHead;
	freeHead = to_add;
	allocated--;
}

template <typename T>
size_t ObjectPool<T>::getCapacity() const {
	return capacity;
}
template <typename T>
size_t ObjectPool<T>::howManyAllocated() const {
	return allocated;
}
template <typename T>
size_t ObjectPool<T>::howManyFree() const {
	return capacity - allocated;
}
