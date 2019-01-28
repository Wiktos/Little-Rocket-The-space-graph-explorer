#include "depth_first_search.h"

DepthFirstSearch::DepthFirstSearch(UndirectedGraph* G, int start) : start(start) {
	this->G = std::make_unique<UndirectedGraph>(*G);
	marked.resize(G->V());
	edgeTo.resize(G->V());
	std::fill(marked.begin(), marked.end(), false);
	std::fill(edgeTo.begin(), edgeTo.end(), NO_EDGE_FROM_VERTEX);
}

void DepthFirstSearch::search() const {
	search(G.get(), 0);
}

void DepthFirstSearch::setStart(int newStart) {
	start = newStart;
}

bool DepthFirstSearch::hasPathTo(int v) const {
	return marked[v];
}

std::stack<int> DepthFirstSearch::pathTo(int v) const {
	std::stack<int> path;
	while (v != start) {
		path.push(v);
		v = edgeTo[v];
	}
	path.push(start);
	return path;
}

std::vector<int> DepthFirstSearch::traceTo(int v) const {
	auto vIter = std::find(trace.begin(), trace.end(), v);
	return std::vector<int>(trace.begin(), ++vIter);
}

void DepthFirstSearch::search(UndirectedGraph* G, int v) const {
	marked[v] = true;
	trace.push_back(v);
	for (int adj : G->adj(v)) {
		if (!marked[adj]) {
			edgeTo[adj] = v;
			search(G, adj);
			trace.push_back(v);
		}
	}
}