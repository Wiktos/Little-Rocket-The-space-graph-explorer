#pragma once

class UndirectedMap;

/*
	UndirectedMapGenerator interface provides 'boundary' between UndirectedMap and UndirecteMapGenerator derived class.
	Solution allows to switch between diffrent generators easily.

	by Wiktor £azarski
*/
class UndirectedMapGenerator
{
public:

	UndirectedMapGenerator(UndirectedMap* map) : map(map)
	{}

	virtual void generateMapPaths(int layers, int nodesInLayer, int layersConnections) const = 0;
	//virtual std::unique_ptr<UndirectedMapGenerator> makeUniquePtr() const = 0;

	virtual ~UndirectedMapGenerator() = default;

protected:

	std::unique_ptr<UndirectedMap> map;
};