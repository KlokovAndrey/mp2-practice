#pragma once
#include "Edge.h" 
#include <ctime> 
#include <cstdlib> 
#include <iostream>
#include<vector>
#include <algorithm> 
using namespace std;
class Graph 
{
private:
	int m;//число ребер 
	int n;// число вершин 
	Edge* Edges;
	int curr;
public:
	Graph(int, int);
	Graph(Graph&);
	~Graph();
	void insert(int, int, int);
	void remove(int, int);
	int findEdge(int, int);
	void Generate(int);
	int GetSize();
	int GetCurr();
	Edge GetEdge(int);
	Edge* getEdges();
	double getWeight(int, int);
	void print();
	int getVerticesNum();
	vector<int> getVertices();
};

Graph::Graph(int m1, int n1)
{
	if (n1 < 0)
		throw "Error";
	else
		n = n1;
	if ((m1 < 0) || (m1 > n1*(n1 - 1) / 2))
		throw "Error";
	m = m1;
	Edges = new Edge[m];
	curr = 0;
}
Graph::Graph(Graph& a)
{
	n = a.n;
	m = a.m;
	Edges = new Edge[m];
	Edge* z = a.getEdges();
	for (int i = 0; i < m; i++)
	{
		Edges[i].Ne = z[i].Ne;
		Edges[i].Ke = z[i].Ke;
		Edges[i].w = z[i].w;
	}
}
Graph::~Graph()
{
	delete[] Edges;
}
int Graph::GetSize()
{
	return m;
}
int Graph::GetCurr()
{
	return curr;
}
Edge Graph::GetEdge(int i)
{
	return Edges[i];
}
int Graph::findEdge(int a, int b)
{
	for (int i = 0; i < curr; i++)
	{
		if ((Edges[i].Ne == a) && (Edges[i].Ke == b) || (Edges[i].Ke == a) && (Edges[i].Ne == b))
			return i;
	}
	return -1;
}
void Graph::insert(int a, int b, int c)
{
	Edge newEdge(a, b, c);
	if (curr == m + 1)
		throw "graph is full";
	if (a == b)
		throw "Error";
	if ((a > n) || (b > n))
		throw ("Error");
	Edges[curr] = newEdge;
	curr++;
}
void Graph::remove(int a, int b)
{
	int tmp = findEdge(a, b);
	if (tmp == -1)
		throw ("there isn't such Edge");
	Edges[tmp].~Edge();
	Edges[tmp] = Edges[curr - 1];
	curr--;
}
Edge* Graph::getEdges()
{
	return Edges;
}
double Graph::getWeight(int a, int b)
{
	return Edges[findEdge(a, b)].w;
}
void Graph::Generate(int b)
{
	int x, y;
	double weight;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		do
		{
			x = rand() % n;
			y = rand() % n;
		} while ((x == y) || (findEdge(x, y) != -1));
		weight = rand()% (b+1);
		Edge newEdge(x, y, weight);
		Edges[i] = newEdge;
		curr++;
	}
}
void Graph::print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < curr; j++)
		{
			if (Edges[j].Ne == i)
				cout << "Ne: " << Edges[j].Ne << "     Ke: " << Edges[j].Ke << "    weight: " << Edges[j].w << endl;
		}
	}
}
int Graph::getVerticesNum()
{
	return n;
}
vector<int> Graph::getVertices()
{
	vector<int> res;
	for (int i = 0; i < m; i++)
	{
		if (find(res.begin(), res.end(), Edges[i].Ne) == res.end())
		{
			res.push_back(Edges[i].Ne);
		}
		if (find(res.begin(), res.end(), Edges[i].Ke) == res.end())
		{
			res.push_back(Edges[i].Ke);
		}
	}
	return res;
}

