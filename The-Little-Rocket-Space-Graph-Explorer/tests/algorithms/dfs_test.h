#pragma once

#include "../error_messenger.h"
#include "../../source_code/algorithms/depth_first_search.h"

namespace dfs_test {

	void testSearching() {
		std::cout << "DepthFirstSearch searching tests\n";

		const std::string ERROR_MSG = "DFS search error ";

		UndirectedGraph G({ {1, 0}, {1, 1}, {1, 2} });
		DepthFirstSearch engine(&G, 0);
		engine.performSearching();

		if (!engine.hasPathTo(2)) {
			ErrorMessenger::getInstance().report(ERROR_MSG + " there exists path to 2");
		}

		std::stack<int> correctPath({ 2, 1, 0 });
		if (correctPath != engine.pathTo(2)) {
			ErrorMessenger::getInstance().report(ERROR_MSG + " wrong path returned");
		}

		ErrorMessenger::getInstance().printReport(std::cout);
	}

}