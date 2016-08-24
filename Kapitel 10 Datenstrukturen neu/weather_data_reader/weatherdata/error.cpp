#include "error.h"

void error(std::string were, std::string what) {
	throw std::runtime_error(were + '\n' + what);
}