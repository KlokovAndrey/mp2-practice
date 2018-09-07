#pragma once
#include "Graph.h" 
#include "PriorityQueue.h" 
#include "Dheap.h" 
#include "SepSets.h"
#include "DHBPQ.h" 
struct Vertex
{
	int j = 0;
	double dist = 0;
	int up = -1;
	double w;
	Vertex() {}
	Vertex(int j, double dist, int up)
	{
		this->dist = dist;
		this->up = up;
		this->j = j;
		w = dist;
	}
	bool operator<(const Vertex& p) const
	{
		return dist < p.dist;
	}
};
template<typename T>
class Algorithms {
public:
	static Graph* Kruskal(Graph&gr, PriorityQueue<T>& queue);
	static void Sort(T*arr, int n, int d);
	static vector<Vertex> dejkstra(Graph *graph, int s, PriorityQueue<Vertex>* queue);
};

template<typename T>
Graph* Algorithms<T>::Kruskal(Graph& gr, PriorityQueue<T>& queue)
{
	int n = gr.GetSize();
	int m = gr.GetCurr();
	Graph* tree = new Graph(n, m);
	SepSets *set = new SepSets(n);
	for (int i = 0; i<n; i++)
		set->create_set(i);
	for (int i = 0; i<m; i++)
		queue.push(gr.GetEdge(i));
	T tmp;
	while ((tree->GetCurr() < n - 1) && (!queue.IsEmpty()))
	{
		tmp = queue.top();
		queue.pop();
		int x = tmp.Ne;
		int y = tmp.Ke;
		int w = tmp.w;
		int Nx = set->find_set(x);
		int Ky = set->find_set(y);
		if (Nx != Ky)
		{
			set->merge_set(Nx, Ky);
			tree->insert(x, y, w);
		}
	}
	return tree;
}

template<typename T>
void Algorithms<T>::Sort(T*arr, int n, int d)
{
	PArr<T>* data = new PArr<T>[n];
	for (int i = 0; i < n; i++)
	{
		data[i].w = arr[i];
	}
	Dheap<PArr<T>> heap(data, n, d);
	heap.hilling();
	for (int i = 0; i < n; i++)
	{
		arr[i] = heap.top().w;
		heap.remove(0);
	}
}

vector<Vertex> Algorithms<void>::dejkstra(Graph *graph, int s, PriorityQueue<Vertex>* queue)
{
	int m = graph->GetCurr();
	int n = graph->getVerticesNum();
	if ((s < 0) || (s >= n))
		throw "Error";
	vector<int> vertex = graph->getVertices();
	vector<double> dist = vector<double>(n, numeric_limits<double>::infinity());
	vector<int> up = vector<int>(n, -1);
	vector<vector<double>> matrix = vector<vector<double>>(n);
	for (int i = 0; i < n; i++) {
		matrix[i] = vector<double>(n, -1.0);
	}
	Edge*Edges = graph->getEdges();
	for (int i = 0; i < m; i++)
	{
		matrix[Edges[i].Ne][Edges[i].Ke] = Edges[i].w;
		matrix[Edges[i].Ke][Edges[i].Ne] = Edges[i].w;
	}
	dist[s] = 0;
	queue->push(Vertex(s, dist[s], up[s]));
	while (!queue->IsEmpty())
	{
		const Vertex p = queue->top();
		queue->pop();
		vector<double> w = matrix[p.j];
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i] == -1)
				continue;
			const double newDist = dist[p.j] + w[i];
			if (newDist < dist[i])
			{
				dist[i] = newDist;
				up[i] = p.j;
				queue->push(Vertex(i, dist[i], up[i]));
			}
		}
	}
	vector<Vertex> result = vector<Vertex>();
	result.reserve(n);
	for (int i = 0; i < n; i++)
	{
		result.push_back(Vertex(i, dist[i], up[i]));
	}
	return result;
}
