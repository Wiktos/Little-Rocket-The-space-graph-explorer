#pragma once
#include <iostream>
#include <vector>
#include <string>

class ErrorMessenger
{
	std::vector<std::string> messages;
	unsigned int errorsCnt;

	ErrorMessenger() : errorsCnt(0)
	{}
	ErrorMessenger(const ErrorMessenger& source) = delete;
	ErrorMessenger& operator=(const ErrorMessenger& rhs) = delete;

public:
	static ErrorMessenger& getInstance() {
		static ErrorMessenger instance;
		return instance;
	}

	void report(std::string msg) {
		messages.push_back(msg);
		errorsCnt++;
	}

	void printReport(std::ostream& os) {
		os << "Errors : " << errorsCnt << '\n';
		for (auto msg : messages) {
			os << msg << '\n';
		}
		messages.clear();
		errorsCnt = 0;
	}
};