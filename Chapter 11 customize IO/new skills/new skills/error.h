#pragma once
#include <string>

void error(std::string what, std::string were) {
	throw std::runtime_error(what + '\n' + were);
}