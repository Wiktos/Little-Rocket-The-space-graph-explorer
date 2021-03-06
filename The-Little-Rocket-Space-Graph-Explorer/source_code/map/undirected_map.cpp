#include <random>
#include "undirected_map.h"

UndirectedMap::UndirectedMap(int layers, int nodesInLayer) : UndirectedGraph(layers * nodesInLayer + 2), layers(layers), nodesInLayer(nodesInLayer), END_NODE_IDX(layers * nodesInLayer + 1)
{
	if (layers < 0 || nodesInLayer < 0) {
		throw std::invalid_argument("UndirectedMap invalid constructor parameters");
	}

	generator = StandardUndirectedMapGenerator();
	generator(this, 2);
}

int UndirectedMap::layersNum() const {
	return layers;
}

int UndirectedMap::nodesPerLayer() const {
	return nodesInLayer;
}

void UndirectedMap::regenerate(int layersConnections) {
	clearConnections();
	generator(this, layersConnections);
}

void UndirectedMap::changeGenerator(std::function<void(UndirectedMap*, int)> newGenerator) {
	generator = newGenerator;
}