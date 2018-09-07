/*
#include"Algorithms.h" 
#include<iostream> 
using namespace std;
int main()
{
	int n, m, s, d;
	vector<Vertex> result;
	cout << "Write number of vertex:" << endl;
	cin >> n;
	cout << "Write number of edges:" << endl;
	cin >> m;
	cout << "Write 'd':" << endl;
	cin >> d;
	DHBPQ<Vertex>* queue = new DHBPQ<Vertex>(d);
	Graph* graph = new Graph(m, n);
	graph->Generate(30);
	graph->print();
	cout << "Zero vertex:" << endl;
	cin >> s;
	result = Algorithms<void>::dejkstra(graph, s, queue);
	cout << "Vertex" << "     Dist" << "     Up" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i].j << "           " << result[i].dist << "       " << result[i].up << endl;
	}
}
*/