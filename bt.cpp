#include <bits/stdc++.h>
using namespace std;
// Creating shortcut for an integer pair
typedef pair<int, int> iPair;
// Structure to represent a graph
struct Graph
{
	int V, E;
	vector<pair<int, iPair>> edges;
	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
	}
	// Utility function to add an edge
	void addEdge(int u, int v, int w)
	{
		edges.push_back({w, {u, v}});
	}
	int kruskalMST();
};
struct DisjointSets
{
	int *parent, *rnk;
	int n;
	DisjointSets(int n)
	{
		this->n = n;
		parent = new int[n + 1];
		rnk = new int[n + 1];
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;
			parent[i] = i;
		}
	}
	int find(int u)
	{
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}
	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else
			parent[x] = y;
		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};
/* Functions returns weight of the MST*/
int Graph::kruskalMST()
{
	int mst_wt = 0;
	// Sort edges in increasing order on basis of cost
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	vector<pair<int, iPair>>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;
		int set_u = ds.find(u);
		int set_v = ds.find(v);
		if (set_u != set_v)
		{
			cout << u << " - " << v << endl;
			mst_wt += it->first;
			ds.merge(set_u, set_v);
		}
	}
	return mst_wt;
}
int main()
{
	cout << "Implementing the minium spanning Tree using Kruskal's algorithm.";
	cout << "\nHere in this code we are assuming\n0 as A\n1 as B\n2 as C";
	cout << "\n3 as D\n4 as E\n5 as F \n;";
	int V = 6, E = 9;
	Graph g(V, E);
	// making above shown graph
	g.addEdge(0, 1, 2);
	g.addEdge(0, 4, 8);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 5, 5);
	g.addEdge(2, 4, 4);
	g.addEdge(3, 0, 1);
	g.addEdge(4, 1, 3);
	g.addEdge(4, 3, 1);
	g.addEdge(4, 5, 7);
	cout << "Edges of MST are \n";
	int mst_wt = g.kruskalMST();
	cout << "\nWeight of MST is " << mst_wt;
	return 0;
}