#pragma once
#include "undirected_graph.h"

/*
	Map class represents the model of undirected graph specified to be a board of visualization.

	by Wiktor £azarski
*/
class UndirectedMap : public UndirectedGraph 
{
public:
	
	UndirectedMap(int layers, int nodesInLayer);


private:

	static const int START_NODE_IDX = 0;
	const int endNodeIdx;
	const int layers;
	const int nodesInLayer;

	void generateMapPaths();
};