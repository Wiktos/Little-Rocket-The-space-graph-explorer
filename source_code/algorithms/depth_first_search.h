#pragma once
#include <vector>
#include <memory>
#include <stack>
#include <algorithm>

#include "../map/undirected_graph.h"

class DepthFirstSearch
{
public:

	DepthFirstSearch(UndirectedGraph* G, int start);

	void search() const;
	void setStart(int newStart);
	bool hasPathTo(int v) const;
	std::stack<int> pathTo(int v) const;
	std::vector<int> traceTo(int v) const;

private:

	static const int NO_EDGE_FROM_VERTEX = -1;

	std::unique_ptr<UndirectedGraph> G;
	mutable std::vector<bool> marked;
	mutable std::vector<int> edgeTo;
	int start;

	mutable std::vector<int> trace;

	void search(UndirectedGraph* G, int v) const;

};