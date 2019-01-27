
#include "undirected_map_tests.h"
#include "../../source_code/map/undirected_map.h"
#include "../error_messenger.h"

void umap_test::testConstructor() {
	const std::string ERROR_MSG = "Error in default constructor "; 

	UndirectedMap map(2, 2);
	if (map.layersNum() != 2) {
		ErrorMessenger::get_instance().report(ERROR_MSG + " number of layers != 2");
	}

	if (map.nodesPerLayer() != 2) {
		ErrorMessenger::get_instance().report(ERROR_MSG + " nodes in layer != 2");
	}
}

void umap_test::testRegenerateMethod() {
	const std::string ERROR_MSG = "Error in regenerate method ";

	UndirectedMap map(2, 2);
	std::string currGraph = UndirectedGraph::toString(map);
	map.regenerate();
	std::string nextGraph = UndirectedGraph::toString(map);

	if (currGraph == nextGraph) {
		ErrorMessenger::get_instance().report(ERROR_MSG + " regenerate method generated the same graph");
	}
}

void umap_test::performAllTests() {
	umap_test::testConstructor();
	umap_test::testRegenerateMethod();

	std::cout << "UndirectedMap tests report : \n";
	ErrorMessenger::get_instance().print_report(std::cout);
}