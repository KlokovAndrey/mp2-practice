#pragma once
#include "PriorityQueue.h"
#include"Dheap.h"
using namespace std;
template <typename T>
class DHBPQ :public PriorityQueue<T> {
private:
	Dheap<T>*heap;
public:
	DHBPQ(int);
	DHBPQ(Dheap<T>&);
	virtual ~DHBPQ() {};
	void push(T);
	void pop();
	T top();
	bool IsFull();
	bool IsEmpty();
	void hill();
};


template<typename T>
DHBPQ<T>::DHBPQ(int d)
{
	heap = new Dheap<T>(d);
}
template<typename T>
DHBPQ<T>::DHBPQ(Dheap<T>& a)
{
	heap = new Dheap<T>(a);
}

template<typename T>
void DHBPQ<T>::push(T elem)
{
	heap->insert(elem);
}
template<typename T>
void DHBPQ<T>::pop()
{
	if (heap->IsEmpty())
		throw"PriorityQueue is empty";
	heap->remove(0);
}
template<typename T>
T DHBPQ<T>::top()
{
	return heap->top();
}
template<typename T>
bool DHBPQ<T>::IsFull() {
	if (heap->IsFull())
		throw "PriorityQueue is full";
	return heap->IsFull();
}
template<typename T>
bool DHBPQ<T>::IsEmpty() {
	return heap->IsEmpty();
}

template<typename T>
void DHBPQ<T>::hill()
{
	heap->hilling();
}