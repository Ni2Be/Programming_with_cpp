#include "Handling.h"


namespace HANDLING
{
	void error(string where, string what)
	{
		throw runtime_error(where + '\n' + what);
	}
}