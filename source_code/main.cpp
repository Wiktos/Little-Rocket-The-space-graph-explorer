#include <iostream>
#include "../tests/map/undirectedgraph_tests.h"
#include "../tests/map/undirected_map_tests.h"

#include "map/undirected_map.h"
#include "algorithms/depth_first_search.h"

int main(int args, char* argv[]) {

	ugraph_test::performAllTests();
	umap_test::performAllTests();

	UndirectedMap* map = new UndirectedMap(3, 4);
	DepthFirstSearch searchEngine(map, UndirectedMap::START_NODE_IDX);
	searchEngine.search();

	std::cout << UndirectedGraph::toString(*map) << std::endl;
	if (searchEngine.hasPathTo(map->END_NODE_IDX)) {
		std::stack<int> path = searchEngine.pathTo(map->END_NODE_IDX);
		while(!path.empty()) {
			std::cout << path.top() << ' ';
			path.pop();
		}
	}

	return 0;
}