#include "console_ui.h"

ApplicationParameters ConsoleUI::start() const {
	printWelcomeMsg();

	ApplicationParameters retv;
	getParameter("Number of layers in map : ", retv.layers);
	getParameter("Number of nodes per layer : ", retv.nodesPerLayer);
	getParameter("Number of connections between layer : ", retv.layersConnections);

	printThanksMsg();

	return retv;
}

void ConsoleUI::printWelcomeMsg() const {
	std::cout << "Welcome in The Little Rocket Space Graph Explorer\n";
	std::cout << "Before you start please specify some map parameters\n";
}

void ConsoleUI::getParameter(const std::string& msg, int& param) const {
	do {
		std::cout << msg;
		std::cin >> param;
	} while (param <= 0);
}

void ConsoleUI::printThanksMsg() const {
	std::cout << "Thank you enjoy the visualisation !";
}