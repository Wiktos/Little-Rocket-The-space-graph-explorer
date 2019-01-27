#include <iostream>
#include "../tests/map/undirectedgraph_tests.h"
#include "map/undirected_map.h"

using namespace std;

int main(int args, char* argv[]) {

	ugraph_test::performAllTests();

	UndirectedMap map(3, 4);

	std::cout << UndirectedGraph::toString(map);

	return 0;
}