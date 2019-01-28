#pragma once
#include <memory>
#include <stack>
#include <vector>

#include "../map/undirected_graph.h"

class SearchAlgorithm 
{
public:

	SearchAlgorithm(UndirectedGraph* G, int start);

	void performSearching() const;
	void setStart(int newStart);
	virtual bool hasPathTo(int v) const = 0;
	virtual std::stack<int> pathTo(int v) const = 0;
	virtual std::vector<int> traceTo(int v) const = 0;

	virtual ~SearchAlgorithm() = default;

protected:

	std::unique_ptr<UndirectedGraph> G;
	int start;
	mutable std::vector<int> trace;

private:

	virtual void search(UndirectedGraph* G, int v) const = 0;
};