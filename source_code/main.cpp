#include <iostream>
#define TESTS_ON

#include "../tests/map/undirectedgraph_tests.h"
#include "../tests/map/undirected_map_tests.h"
#include "../tests/algorithms//dfs_test.h"

int main(int args, char* argv[]) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#ifdef TESTS_ON
	std::cout << "Unit tests : " << __DATE__ << ' ' << __TIME__ << std::endl;
	ugraph_test::performAllTests();
	umap_test::performAllTests();
	dfs_test::testSearching();
#endif // TESTS_ON



	return 0;
}