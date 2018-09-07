#pragma once
struct Edge {
	int Ne;
	int Ke;
	double w;
	Edge(int a, int b, double c)
	{
		Ne = a;
		Ke = b;
		w = c;
	};
	Edge() {};
	Edge& operator=(Edge&a)
	{
		Ne = a.Ne;
		Ke = a.Ke;
		w = a.w;
		return *this;
	}
};

bool operator ==(Edge a, Edge b)
{
	if ((a.Ne == b.Ne) && (a.Ke == b.Ke) && (a.w == b.w))
		return true;
	else
		return false;
}