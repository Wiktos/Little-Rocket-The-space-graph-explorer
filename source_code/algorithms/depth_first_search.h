#pragma once
#include <algorithm>

#include "search_algorithm.h"

class DepthFirstSearch final : public SearchAlgorithm
{
public:

	DepthFirstSearch(UndirectedGraph* G, int start);

	bool hasPathTo(int v) const override;
	std::stack<int> pathTo(int v) const override;
	std::vector<int> traceTo(int v) const override;

private:

	static const int NO_EDGE_FROM_VERTEX = -1;

	mutable std::vector<bool> marked;
	mutable std::vector<int> edgeTo;

	void search(UndirectedGraph* G, int v) const override;

};