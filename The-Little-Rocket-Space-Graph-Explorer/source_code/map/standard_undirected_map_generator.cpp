#include <random>

#include "standard_undirected_map_generator.h"
#include "undirected_map.h"

std::random_device device;
std::default_random_engine engine(device());
std::uniform_int_distribution<int> uniformDistribution;

void connectLayers(int layers, int nodesInLayer, int layersConnection, UndirectedMap* const map);
void connectStartingNode(int nodesInLayer, UndirectedMap* const map);
void connectLastNode(int nodesInLayer, UndirectedMap* const map);

void StandardUndirectedMapGenerator::operator()(UndirectedMap* map, int layersConnections) const {
	connectLayers(map->layersNum(), map->nodesPerLayer(), layersConnections, map);
	connectStartingNode(map->nodesPerLayer(), map);
	connectLastNode(map->nodesPerLayer(), map);
}

void connectLayers(int layers, int nodesInLayer, int layersConnection, UndirectedMap* const map) {
	for (int i = 0; i < layers; i++) {

		for (int j = 1; j < nodesInLayer; j++) {
			//connects nodes of one layer
			map->addEdge(j + i * nodesInLayer, j + i * nodesInLayer + 1);
		}

		//interlayers connections
		if (i < layers - 1) {
			std::uniform_int_distribution<int> currLayerDistribution(i * nodesInLayer + 1, i * nodesInLayer + nodesInLayer);
			std::uniform_int_distribution<int> nextLayerDistribution = std::uniform_int_distribution<int>((i + 1) * nodesInLayer + 1, (i + 1) * nodesInLayer + nodesInLayer);

			for (int j = 0; j < layersConnection; j++) {
				map->addEdge(currLayerDistribution(engine), nextLayerDistribution(engine));
			}
		}
	}
}

void connectStartingNode(int nodesInLayer, UndirectedMap* const map) {
	uniformDistribution = std::uniform_int_distribution<int>(1, nodesInLayer);
	for (int i = 1; i < nodesInLayer; i++) {
		map->addEdge(UndirectedMap::START_NODE_IDX, uniformDistribution(engine));
	}
}

void connectLastNode(int nodesInLayer, UndirectedMap* const map) {
	uniformDistribution = std::uniform_int_distribution<int>(map->V() - 1 - nodesInLayer, map->END_NODE_IDX - 1);
	for (int i = 1; i < nodesInLayer; i++) {
		map->addEdge(map->END_NODE_IDX, uniformDistribution(engine));
	}
}