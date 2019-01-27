#include <iostream>
#include "../tests/map/undirectedgraph_tests.h"
#include "../tests/map/undirected_map_tests.h"

#include "map/undirected_map.h"
#include "algorithms/depth_first_search.h"

int main(int args, char* argv[]) {

	ugraph_test::performAllTests();
	umap_test::performAllTests();

	UndirectedMap* map = new UndirectedMap(5, 10);
	DepthFirstSearch searchEngine(map, UndirectedMap::START_NODE_IDX);
	searchEngine.search();

	std::cout << UndirectedGraph::toString(*map) << std::endl;
	if (searchEngine.hasPathTo(map->END_NODE_IDX)) {
		for (int w : searchEngine.pathTo(map->END_NODE_IDX)) {
			std::cout << w << ' ';
		}
	}

	return 0;
}