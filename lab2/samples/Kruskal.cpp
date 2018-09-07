
#include"Algorithms.h" 
#include <iostream> 
using namespace std;
int main()
{
	try {
		int n, m, d;
		cout << "Write number of vertex:" << endl;
		cin >> n;
		cout << "Write number of edges:" << endl;
		cin >> m;
		cout << "Write 'd':" << endl;
		cin >> d;
		Graph graph(m, n);
		graph.Generate(30);
		graph.print();
		DHBPQ<Edge> queue(d);
		Graph* NewGraph = Algorithms<Edge>::Kruskal(graph, queue);
		cout << endl << endl << "       Result:" << endl << endl << endl;
		NewGraph->print();
	}
	catch (const char*ex)
	{
		cout << endl << ex;
	}
}

