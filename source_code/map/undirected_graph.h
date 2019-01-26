#pragma once
#include <vector>
#include <forward_list>
#include <exception>
#include <algorithm>
#include <string>

/*
	Graph class represents undirected graph's API.
	Neighbour's lists were used as a representation structure of graph.

	by Wiktor �azarski
*/
class UndirectedGraph
{
public:

	static int degree(const UndirectedGraph& G, int v);
	static int maxDegree(const UndirectedGraph& G);
	static int avgDegree(const UndirectedGraph& G);
	static int numberOfSelfLoops(const UndirectedGraph& G);
	static std::string toString(const UndirectedGraph& G);

	explicit UndirectedGraph(int V);
	UndirectedGraph(const std::initializer_list<std::pair<int, int>>& ls);
	UndirectedGraph(const UndirectedGraph&) = default;
	UndirectedGraph(UndirectedGraph&&) = default;

	UndirectedGraph& operator=(const UndirectedGraph&) = default;
	UndirectedGraph& operator=(UndirectedGraph&&) = default;

	int V() const;
	int E() const;
	void addEdge(int v, int w);
	std::forward_list<int> adj(int v) const;

private:
	std::vector<std::forward_list<int>> graph;
	const int vertices;
	int edges;

	void checkVertex(int v) const;
	void addSelfLoop(int v);
};