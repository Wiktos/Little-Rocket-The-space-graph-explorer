#include <random>
#include "undirected_map.h"

UndirectedMap::UndirectedMap(int layers, int nodesInLayer) : UndirectedGraph(layers * nodesInLayer + 2),
layers(layers),
nodesInLayer(nodesInLayer),
endNodeIdx(layers * nodesInLayer + 1)
{
	if (layers < 0 || nodesInLayer < 0) {
		throw std::invalid_argument("UndirectedMap invalid constructor parameters");
	}

	generateMapPaths();
}

void UndirectedMap::generateMapPaths() {
	//connect layer node
	for (int i = 0; i < layers; i++) {
		for (int j = 1; j < nodesInLayer; j++) {
			addEdge(j + i * nodesInLayer, j + i * nodesInLayer + 1);
		}
	}

	//connect start node to first layer
	std::random_device device;
	std::default_random_engine engine(device());
	std::uniform_int_distribution<int> uniformDistribution(1, nodesInLayer);
	for (int i = 1; i < nodesInLayer; i++) {
		addEdge(START_NODE_IDX, uniformDistribution(engine));
	}

	//connect end node to last layer
	uniformDistribution = std::uniform_int_distribution<int>(endNodeIdx - nodesInLayer, endNodeIdx - 1);
	for (int i = 1; i < nodesInLayer; i++) {
		addEdge(endNodeIdx, uniformDistribution(engine));
	}
}