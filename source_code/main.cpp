#include <iostream>
#include "../tests/map/undirectedgraph_tests.h"
#include "../tests/map/undirected_map_tests.h"
#include "../tests/algorithms//dfs_test.h"

int main(int args, char* argv[]) {

	ugraph_test::performAllTests();
	umap_test::performAllTests();
	dfs_test::testSearching();

	return 0;
}