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

	std::random_device device;
	std::default_random_engine engine(device());
	std::uniform_int_distribution<int> uniformDistribution;
	//connect layer node
	for (int i = 0; i < layers; i++) {

		for (int j = 1; j < nodesInLayer; j++) {
			//connects with themselves
			addEdge(j + i * nodesInLayer, j + i * nodesInLayer + 1);
		}

		//connects layers
		if (i < layers - 1) {
			std::uniform_int_distribution<int> currLayerDistribution(i * nodesInLayer + 1, i * nodesInLayer + nodesInLayer);
			std::uniform_int_distribution<int> nextLayerDistribution = std::uniform_int_distribution<int>((i + 1) * nodesInLayer, (i + 1) * nodesInLayer + nodesInLayer);

			for (int j = 0; j < 2; j++) {
				//connects with next layer
				addEdge(currLayerDistribution(engine), nextLayerDistribution(engine));
			}
		}
	}

	//connect start node to first layer
	uniformDistribution = std::uniform_int_distribution<int>(1, nodesInLayer);
	for (int i = 1; i < nodesInLayer; i++) {
		addEdge(START_NODE_IDX, uniformDistribution(engine));
	}

	//connect end node to last layer
	uniformDistribution = std::uniform_int_distribution<int>(endNodeIdx - nodesInLayer, endNodeIdx - 1);
	for (int i = 1; i < nodesInLayer; i++) {
		addEdge(endNodeIdx, uniformDistribution(engine));
	}
}