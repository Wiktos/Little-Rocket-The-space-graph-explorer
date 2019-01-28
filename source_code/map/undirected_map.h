#pragma once
#include <functional>

#include "undirected_graph.h"
#include "standard_undirected_map_generator.h"

/*
	Map class represents the model of undirected graph specified to be a board of visualization.

	by Wiktor £azarski
*/
class UndirectedMap : public UndirectedGraph 
{
public:
	
	static const int START_NODE_IDX = 0;
	const int END_NODE_IDX;

	UndirectedMap(int layers, int nodesInLayer);
	UndirectedMap(const UndirectedMap&) = delete;
	UndirectedMap(UndirectedMap&&) = delete;
	
	UndirectedMap& operator=(const UndirectedMap&) = delete;
	UndirectedMap& operator=(UndirectedMap&&) = delete;

	int layersNum() const;
	int nodesPerLayer() const;

	void regenerate(int layersConnections);
	void changeGenerator(std::function<void(UndirectedMap*, int)> newGenerator);

	~UndirectedMap() = default;

private:

	const int layers;
	const int nodesInLayer;
	
	std::function<void(UndirectedMap*, int)> generator;
};