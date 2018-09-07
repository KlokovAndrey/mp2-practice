#pragma once
#include"Graph.h"
#include <cmath> 
#define MAXSIZE 100; 
template<typename K>
class PArr
{
public:
	K w;
};

template<typename T>
class Dheap {
private:
	int d; // арность
	int m;// максимальное число элементов 
	T* keys;
	int curr;// текущее
public:
	Dheap(int);
	Dheap(int, int);
	Dheap(T*, int, int);
	Dheap(const Dheap<T>&);
	Dheap(Graph&, int);
	~Dheap();
	void tr(int, int); // транспонирование
	void down(int); // погружение
	void up(int); // всплытие
	void hilling();  // окучивание
	int find(T);
	void insert(T);
	void remove(int);
	int MinChild(int); // получение индекса элемента с минимальным ключом
	bool IsFull();
	bool IsEmpty();
	int GetParent(int); // возвращает индекс родителя
	T top();
	void print();
};
template <typename T>
void Dheap<T>::print()
{
	int level = 0, tmp = 0;
	while (tmp < curr)
	{
		tmp += pow(d, level);
		level++;
	}
	int k = 1, z = 0;
	cout << "\t" << keys[0].w << endl;
	for (int i = 1; i < level; i++)
	{
		for (int j = k; (j < k + pow(d, i)) && (j < curr); j++)
			cout << keys[j].w << "\t";
		cout << endl;
		if (k + pow(d, i) > curr)
			k = curr;
		else k += pow(d, i);
	}
}

template<typename T>
Dheap<T>::Dheap(int d)
{
	if (d < 1)
		throw"wrong d";
	m = MAXSIZE;
	this->d = d;
	keys = new T[m];
	curr = 0;
}
template<typename T>
Dheap<T>::Dheap(int _m, int _d)
{
	d = _d;
	m = _m;
	curr = 0;
	keys = new T[_m];
}
template<typename T>
Dheap<T>::Dheap(T *a, int m, int d)
{
	this->d = d;
	this->m = m;
	curr = m;
	keys = new T[m];
	for (int i = 0; i < m; i++)
	{
		keys[i] = a[i];
	}
}
template<typename T>
Dheap<T>::Dheap(const Dheap<T>&a)
{
	d = a.d;
	m = a.m;
	keys = new T[m];
	curr = a.curr;
	for (int i = 0; i<curr; i++)
	{
		keys[i] = a.keys[i];
	}
}
template<typename T>
Dheap<T>::Dheap(Graph& Graph, int _d)
{
	d = _d;
	m = Graph.GetSize();
	keys = new T[m];
	Edge* a = Graph.getEdges();
	for (int i = 0; i < Graph.GetSize(); i++)
	{
		keys[i] = a[i];
	}
	curr = m;
}
template<typename T>
Dheap<T>::~Dheap()
{
	delete[] keys;
}
template<typename T>
void Dheap<T>::tr(int i, int p)
{
	T tmp = keys[i];
	keys[i] = keys[p];
	keys[p] = tmp;
}
template<typename T>
void Dheap<T>::down(int i)
{
	int s = MinChild(i);
	while ((s != 0) && (keys[i].w > keys[s].w))
	{
		tr(i, s);
		i = s;
		s = MinChild(i);
	}
}
template<typename T>
void Dheap<T>::up(int i)
{
	int p = GetParent(i);
	while ((i != 0) && (keys[p].w > keys[i].w))
	{
		tr(i, p);
		i = p;
		p = GetParent(i);
	}
}


template<typename T>
int Dheap<T>::MinChild(int a)
{
	int minCh = a*d + 1;
	int maxCh;
	if (minCh >= curr) return 0;
	if (a*d + d < curr - 1)
		maxCh = a*d + d;
	else maxCh = curr - 1;
	for (int i = minCh; i <= maxCh; i++)
	{
		if (keys[i].w < keys[minCh].w)
		{
			minCh = i;
		}
	}
	return minCh;
}
template<typename T>
void Dheap<T>::hilling()
{
	for (int i = curr - 1; i >= 0; i--)
	{
		down(i);
	}
}
template<typename T>
int Dheap<T>::find(T a)
{
	for (int i = 0; i < m; i++)
	{
		if (keys[i] == a)return i;
	}
	throw"Element not found";
}
template<typename T>
void Dheap<T>::insert(T a)
{
	if (IsFull())
		throw "Dheap is full";
	keys[curr] = a;
	curr++;
}
template <typename T>
void Dheap<T>::remove(int i)
{
	if (IsEmpty())
		throw"Dheap is empty";
	T tmp = keys[curr - 1];
	keys[curr - 1] = keys[i];
	keys[i] = tmp;
	curr--;
	if ((i != 0) && (keys[i].w< keys[GetParent(i)].w))
		up(i);
	else down(i);
}
template<typename T>
bool Dheap<T>::IsFull()
{
	return (curr == m);
}
template<typename T>
inline bool Dheap<T>::IsEmpty()
{
	return (curr == 0);
}
template<typename T>
int Dheap<T>::GetParent(int i)
{
	int res = i - 1 / d;
	return res;
}
template<typename T>
T Dheap<T>::top()
{
	return keys[0];
}
