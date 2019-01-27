#include "standard_undirected_map_generator.h"
#include "undirected_map.h"

void StandardUndirectedMapGenerator::generateMapPaths(int layers, int nodesInLayer, int layersConnections) const {
	std::random_device device;
	std::default_random_engine engine(device());
	std::uniform_int_distribution<int> uniformDistribution;
	//connect layer node
	for (int i = 0; i < layers; i++) {

		for (int j = 1; j < nodesInLayer; j++) {
			//connects with themselves
			map->addEdge(j + i * nodesInLayer, j + i * nodesInLayer + 1);
		}

		//connects layers
		if (i < layers - 1) {
			std::uniform_int_distribution<int> currLayerDistribution(i * nodesInLayer + 1, i * nodesInLayer + nodesInLayer);
			std::uniform_int_distribution<int> nextLayerDistribution = std::uniform_int_distribution<int>((i + 1) * nodesInLayer, (i + 1) * nodesInLayer + nodesInLayer);

			for (int j = 0; j < 2; j++) {
				//connects with next layer
				map->addEdge(currLayerDistribution(engine), nextLayerDistribution(engine));
			}
		}
	}

	//connect start node to first layer
	uniformDistribution = std::uniform_int_distribution<int>(1, nodesInLayer);
	for (int i = 1; i < nodesInLayer; i++) {
		map->addEdge(UndirectedMap::START_NODE_IDX, uniformDistribution(engine));
	}

	//connect end node to last layer
	uniformDistribution = std::uniform_int_distribution<int>(map->V() - 1 - nodesInLayer, map->END_NODE_IDX - 1);
	for (int i = 1; i < nodesInLayer; i++) {
		map->addEdge(map->END_NODE_IDX, uniformDistribution(engine));
	}
}