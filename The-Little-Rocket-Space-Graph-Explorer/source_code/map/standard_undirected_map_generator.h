#pragma once

class UndirectedMap;

/*
	StandardUndirectedMapGenerator provides default implementation of generation of graph that will be searched.
	Description of an gererating algorithm will be presented on Github repository - README section.
	Link to orginal repository : https://github.com/Wiktos/The-Little-Rocket-Space-Graph-Explorer

	by Wiktor £azarski
*/
class StandardUndirectedMapGenerator
{
public :

	StandardUndirectedMapGenerator() = default;

	void operator()(UndirectedMap* map, int layersConnections) const;

	~StandardUndirectedMapGenerator() = default;

};