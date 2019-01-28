#pragma once

#include "undirected_map_generator.h"

/*
	StandardUndirectedMapGenerator provides default implementation of generation of graph that will be searched.
	Description of an gererating algorithm will be presented on Github repository - README section.
	Link to orginal repository : https://github.com/Wiktos/The-Little-Rocket-Space-Graph-Explorer

	by Wiktor £azarski
*/
class StandardUndirectedMapGenerator final : public UndirectedMapGenerator
{
public :

	StandardUndirectedMapGenerator(UndirectedMap* map) : UndirectedMapGenerator(map)
	{}

	void generateMapPaths(int layers, int nodesInLayer, int layersConnections) const override;

	~StandardUndirectedMapGenerator() = default;

};