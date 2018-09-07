#pragma once
#include"Edge.h"

template<typename T>

class PriorityQueue
{
public:
	PriorityQueue() {};
	virtual void pop() = 0;
	virtual void push(T) = 0;
	virtual T top() = 0;
	virtual void hill() = 0;
	virtual bool IsFull() = 0;
	virtual bool IsEmpty() = 0;
};
