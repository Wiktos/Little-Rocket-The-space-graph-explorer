#pragma once
#include <vector>
#include <memory>
#include <stack>
#include <queue>
#include <algorithm>

#include "../map/undirected_graph.h"

class DepthFirstSearch
{
	static const int NO_EDGE_FROM_VERTEX = -1;

public:

	DepthFirstSearch(UndirectedGraph* G, int start) : start(start) {
		this->G = std::make_unique<UndirectedGraph>(*G);
		marked.resize(G->V());
		edgeTo.resize(G->V());
		std::fill(marked.begin(), marked.end(), false);
		std::fill(edgeTo.begin(), edgeTo.end(), NO_EDGE_FROM_VERTEX);
	}

	void search() const {
		search(G.get(), 0);
	}

	void setStart(int newStart) {
		start = newStart;
	}

	bool hasPathTo(int v) const {
		return marked[v];
	}

	std::stack<int> pathTo(int v) const {
		std::stack<int> path;
		while (v != start) {
			path.push(v);
			v = edgeTo[v];
		}
		path.push(start);
		return path;
	}

	std::queue<int> algorithmTrace() const {
		return trace;
	}

private:

	std::unique_ptr<UndirectedGraph> G;
	mutable std::vector<bool> marked;
	mutable std::vector<int> edgeTo;
	int start;

	mutable std::queue<int> trace;

	void search(UndirectedGraph* G, int v) const {
		marked[v] = true;
		for (int adj : G->adj(v)) {
			if (!marked[adj]) {
				trace.push(v);
				edgeTo[adj] = v;
				search(G, adj);
			}

		}
	}
};