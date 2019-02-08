#include "console_ui.h"

ApplicationParameters ConsoleUI::start() const {
	std::cout << "Welcome in The Little Rocket Space Graph Explorer\n";
	std::cout << "Before you start please specify some map parameters\n";

	ApplicationParameters retv;
	std::cout << "Number of layers in map : ";
	std::cin >> retv.layers;

	std::cout << "Number of nodes per layer : ";
	std::cin >> retv.nodesPerLayer;

	std::cout << "Number of connections between layer : ";
	std::cin >> retv.layersConnections;

	std::cout << "Thank you enjoy the visualisation !";

	return retv;
}