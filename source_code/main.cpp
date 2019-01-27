#include <iostream>
#include "../tests/map/undirectedgraph_tests.h"
#include "../tests/map/undirected_map_tests.h"

using namespace std;

int main(int args, char* argv[]) {

	ugraph_test::performAllTests();
	umap_test::performAllTests();

	return 0;
}