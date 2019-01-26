#include "undirectedgraph_tests.h"

void ugraph_test::testDefauldConstructor() {
	UndirectedGraph G(5);

	if (G.V() != 5) {
		ErrorMessenger::get_instance().report("Error in default constructor test G.V() != 5");
	}

	if (G.E() != 0) {
		ErrorMessenger::get_instance().report("Error in default constructor test G.E() != 0");
	}
}

void ugraph_test::performAllTests() {
	ugraph_test::testDefauldConstructor();

	ErrorMessenger::get_instance().print_report(std::cout);
}