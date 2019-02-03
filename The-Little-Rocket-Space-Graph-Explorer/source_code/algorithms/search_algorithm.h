#pragma once
#include <memory>
#include <stack>
#include <vector>

#include "../map/undirected_graph.h"

/*
	SearchAlgorithm is an interface that describe rules that must be fullfilled by a class implementing search algorithms so that
	it will be possible for final program to visualise algorithm.

	by Wiktor £azarski
*/
class SearchAlgorithm 
{
	virtual void search(UndirectedGraph* G, int v) const = 0;

protected:

	std::unique_ptr<UndirectedGraph> G;
	int start;
	mutable std::vector<int> trace;

public:

	SearchAlgorithm(UndirectedGraph* G, int start);

	void performSearching() const;
	void setStart(int newStart);
	virtual bool hasPathTo(int v) const = 0;
	virtual std::stack<int> pathTo(int v) const = 0;
	virtual std::vector<int> traceTo(int v) const = 0;

	virtual ~SearchAlgorithm() = default;
};