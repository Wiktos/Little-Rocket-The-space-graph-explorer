#include "undirectedgraph_tests.h"

void ugraph_test::testDefauldConstructor() {
	const std::string ERROR_MSG = "Error in default constructor test ";

	UndirectedGraph G(5);

	if (G.V() != 5) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "G.V() != 5");
	}

	if (G.E() != 0) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "G.E() != 0");
	}
}

void ugraph_test::testInitializerListConstructor() {
	const std::string ERROR_MSG = "Error in constructor with initializer list test ";
	
	UndirectedGraph G({ {1, 0}, {1, 1}, {1, 2} });

	if (G.V() != 3) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "G.V() != 3");
	}

	if (G.E() != 3) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "G.E() != 3");
	}
}

void ugraph_test::testAdjMethod() {
	const std::string ERROR_MSG = "Error in adj method test ";
	UndirectedGraph G({ {1, 0}, {1, 1}, {1, 2} });

	std::forward_list<int> adjOne = G.adj(1);
	std::forward_list<int> properOut = { 2, 1, 0 };
	if (adjOne != properOut) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "Wrong vertices adj to one");
	}
}

void ugraph_test::testAddEdgeMethod() {
	const std::string ERROR_MSG = "Error in addEdge method test ";
	UndirectedGraph G(5);
	G.addEdge(2, 1);

	std::forward_list<int> adjOne = G.adj(1);
	std::forward_list<int> properOut = { 2 };
	if (adjOne != properOut) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "Wrong vertice added to one");
	}

	if (G.E() != 1) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "Wrong number of vertices");
	}

	try {
		G.addEdge(2, -2);
		ErrorMessenger::get_instance().report(ERROR_MSG + "exception should be thrown wrong idx");
	}
	catch(std::invalid_argument&){}
	try {
		G.addEdge(20, 2);
		ErrorMessenger::get_instance().report(ERROR_MSG + "exception should be thrown wrong idx");
	}
	catch (std::invalid_argument&) {}

}

void ugraph_test::testDegreeMethod() {
	const std::string ERROR_MSG = "Error in degree static method test ";
	UndirectedGraph G({ {1, 0}, {1, 1}, {1, 2} });

	if (UndirectedGraph::degree(G, 1) != 3) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "wrong degree of vertex 1");
	}

	if (UndirectedGraph::degree(G, 0) != 1) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "wrong degree of vertex 0");
	}
}

void ugraph_test::testMaxDegreeMethod() {
	const std::string ERROR_MSG = "Error in maxDegree static method test ";
	UndirectedGraph G({ {1, 0}, {1, 1}, {1, 2} });

	if (UndirectedGraph::maxDegree(G) != 3) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "max degree should be equal to 3");
	}
}

void ugraph_test::testNumberOfSelfLoopsMethod() {
	const std::string ERROR_MSG = "Error in numberOfSelfLoops static method test ";
	UndirectedGraph G({ {1, 0}, {1, 1}, {1, 2} });

	if (UndirectedGraph::numberOfSelfLoops(G) != 1) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "number of self loops != 1");
	}
}

void ugraph_test::testAreNeighboursMethod() {
	const std::string ERROR_MSG = "Error in areNeighbours method test ";
	UndirectedGraph G({ {1, 0}, {1, 1}, {1, 2} });

	if(G.areNeighbours(2, 0)) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "2, 0 aren't neighbours");
	}

	if (!G.areNeighbours(2, 1)) {
		ErrorMessenger::get_instance().report(ERROR_MSG + "2, 1 are neighbours");
	}
}

void ugraph_test::performAllTests() {
	ugraph_test::testDefauldConstructor();
	ugraph_test::testInitializerListConstructor();
	ugraph_test::testAdjMethod();
	ugraph_test::testAddEdgeMethod();
	ugraph_test::testDegreeMethod();
	ugraph_test::testMaxDegreeMethod();
	ugraph_test::testNumberOfSelfLoopsMethod();
	ugraph_test::testAreNeighboursMethod();

	std::cout << "UndirectedGraph tests report : \n";
	ErrorMessenger::get_instance().print_report(std::cout);
}