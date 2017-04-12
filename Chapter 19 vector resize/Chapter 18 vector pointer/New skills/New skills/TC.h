#pragma once
#include <iostream>
#include <string>

using namespace std;
//Constructor Test Class
class CTC
{
public:
	int val;
	void out(const string& s, int v);
	CTC() { out("CTC()", 0); val = 0; }
	explicit CTC(int v) { out("CTC(int)", v); val = v; }
	CTC(const CTC& ctc) { out("CTC(CTC&)", ctc.val); val = ctc.val; }
	CTC& operator=(const CTC& ctc) { out("CTC::operator=()", ctc.val); val = ctc.val; return *this; }
	~CTC() { out("~CTC()", 0); }

};

//CTC glob(2);

CTC copy(CTC a);

CTC copy2(CTC a);

CTC& ref_to(CTC& a);

CTC* make(int i);

struct XX { CTC a; CTC b; };