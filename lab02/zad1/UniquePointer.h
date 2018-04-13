#pragma once
#include <iostream>

template <typename T>
class UniquePointer {
public:
	UniquePointer(T* ptr) : ptr(ptr) {}

	~UniquePointer() {
		delete ptr;
	}

	UniquePointer(UniquePointer &) = delete;
	UniquePointer(UniquePointer &&uptr) {
		std::cout << "Move constructor" << std::endl;
		ptr = uptr.ptr;
		uptr.ptr = nullptr; // Without this object will be deleted
	}

	void operator=(UniquePointer &) = delete;
	void operator=(UniquePointer &&uptr) {
		std::cout << "Move assigment" << std::endl;
		if (ptr != uptr.ptr) {
			delete ptr;
			ptr = uptr.ptr;
			uptr.ptr = nullptr; // Without this object will be deleted
		}
	}

	explicit operator bool() {
		return ptr != nullptr;
	}

	T& operator*() {
		return *ptr;
	}

	T* Get() {
		return ptr;
	}
private:
	T *ptr;
};