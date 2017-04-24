#include "TC.h"

void CTC::out(const string& s, int v)
{
	cerr << this << "->" << s << ": " << val << " (" << v << ")\n";
}

CTC copy(CTC a) { return a; };

CTC copy2(CTC a) { CTC b = a; return b; };

CTC& ref_to(CTC& a) { return a; }

CTC* make(int i) { CTC a(i); return new CTC(a); }

