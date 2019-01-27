#include <random>
#include "undirected_map.h"

UndirectedMap::UndirectedMap(int layers, int nodesInLayer) : UndirectedGraph(layers * nodesInLayer + 2), layers(layers), nodesInLayer(nodesInLayer), END_NODE_IDX(layers * nodesInLayer + 1)
{
	if (layers < 0 || nodesInLayer < 0) {
		throw std::invalid_argument("UndirectedMap invalid constructor parameters");
	}

	generator = std::make_unique<UndirectedMapGenerator*>(new StandardUndirectedMapGenerator(this));
	(*generator)->generateMapPaths(layers, nodesInLayer, nodesInLayer / 2);
}

int UndirectedMap::layersNum() const {
	return layers;
}

int UndirectedMap::nodesPerLayer() const {
	return nodesInLayer;
}

void UndirectedMap::regenerate() {
	(*generator)->generateMapPaths(layers, nodesInLayer, nodesInLayer / 2);
}

void UndirectedMap::changeGenerator(UndirectedMapGenerator* newGenerator) {
	this->generator = std::move(std::make_unique< UndirectedMapGenerator*>(newGenerator));
}