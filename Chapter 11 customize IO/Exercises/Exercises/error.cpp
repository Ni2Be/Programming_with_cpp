#include "error.h"

void error(std::string where, std::string what) {
	throw std::runtime_error(where + '\n' + what);
}
