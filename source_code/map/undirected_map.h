#pragma once
#include "undirected_graph.h"

/*
	Map class represents the model of undirected graph specified to be a board of visualization.

	by Wiktor £azarski
*/
class UndirectedMap : public UndirectedGraph 
{
public:
	
	UndirectedMap(int layers, int nodesInLayer) : UndirectedGraph(layers * nodesInLayer + 2),
												  layers(layers),
												  nodesInLayer(nodesInLayer),
												  endNodeIdx(layers * nodesInLayer + 1) 
	{
		if (layers < 0 || nodesInLayer < 0) {
			throw std::invalid_argument("UndirectedMap invalid constructor parameters");
		}
	}



private:

	static const int START_NODE_IDX = 0;
	const int endNodeIdx = 0;
	const int layers;
	const int nodesInLayer;

};