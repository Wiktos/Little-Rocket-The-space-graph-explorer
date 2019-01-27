#pragma once
#include "../source_code/map/undirected_graph.h"
#include "../tests/error_messenger.h"

namespace ugraph_test {

	void performAllTests();
	void testDefauldConstructor();
	void testInitializerListConstructor();
	void testAdjMethod();
	void testAddEdgeMethod();
	void testDegreeMethod();
	void testMaxDegreeMethod();
	void testNumberOfSelfLoopsMethod();
	void testAreNeighboursMethod();
}