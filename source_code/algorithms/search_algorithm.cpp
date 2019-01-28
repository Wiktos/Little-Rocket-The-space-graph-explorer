#include "search_algorithm.h"

SearchAlgorithm::SearchAlgorithm(UndirectedGraph* G, int start) : start(start) {
	this->G = std::make_unique<UndirectedGraph>(*G);
}

void SearchAlgorithm::performSearching() const {
	search(G.get(), start);
}

void SearchAlgorithm::setStart(int newStart) {
	start = newStart;
}