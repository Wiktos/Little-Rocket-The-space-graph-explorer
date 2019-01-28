#include "search_algorithm.h"

void SearchAlgorithm::performSearching() const {
	search(G.get(), start);
}

void SearchAlgorithm::setStart(int newStart) {
	start = newStart;
}