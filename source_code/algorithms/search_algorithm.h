#pragma once
#include <memory>
#include <stack>
#include <vector>

#include "../map/undirected_graph.h"

class SearchAlgorithm 
{
public:

	SearchAlgorithm(UndirectedGraph* G, int start) : start(start) {
		this->G = std::make_unique<UndirectedGraph>(*G);
	}

	void performSearching() const;
	void setStart(int newStart);
	virtual bool hasPathTo(int v) const = 0;
	virtual std::stack<int> pathTo(int v) const = 0;
	virtual std::vector<int> traceTo(int v) const = 0;

protected:

	std::unique_ptr<UndirectedGraph> G;
	int start;
	mutable std::vector<int> trace;

private:

	virtual void search(UndirectedGraph* G, int v) const = 0;
};