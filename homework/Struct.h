#pragma once

#include <Node.h>


template<class T>
struct Stack {
	Node<T>* first;
	size_t size;

public:
	Stack();
	~Stack();
};