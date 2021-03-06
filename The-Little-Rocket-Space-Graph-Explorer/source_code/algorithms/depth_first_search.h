#pragma once
#include "search_algorithm.h"

/*
	DepthFirstSearch class provides an implementation of depht first search aplgorithms.
	It implements SearchAlgorithm interface and can be visualised in final program.

	by Wiktor �azarski
*/
class DepthFirstSearch final : public SearchAlgorithm
{
	static const int NO_EDGE_FROM_VERTEX = -1;

	mutable std::vector<bool> marked;
	mutable std::vector<int> edgeTo;

	void search(UndirectedGraph* G, int v) const override;

public:

	DepthFirstSearch(UndirectedGraph* G, int start);

	bool hasPathTo(int v) const override;
	std::stack<int> pathTo(int v) const override;
	std::vector<int> traceTo(int v) const override;
};