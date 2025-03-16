#include "D:\Dev\Ewu-Blaster\EwuBlaster\includes\utils\objectpool.h"

template <typename T>
objectPool<T>::objectPool(size_t size) {
	object_pools.resize(size);
	for (size_t i = 0; i < size; i++) {
		object_pools[i] = new T();
		allocated.push_back(object_pools[i]);
	}
}

template <typename T>
objectPool<T>::~objectPool() {
	for (T* ptr : object_pools) {
		delete ptr;
	}
}


template <typename T>
T* objectPool<T>::borrow() {
	if (!allocated.empty()) {
		T* obj = allocated.back();
		allocated.pop_back();
		return obj;
	}
	return nullptr;
}

template<typename T>
void objectPool<T>::release(T* obj) {
	allocated.push_back(obj);
}