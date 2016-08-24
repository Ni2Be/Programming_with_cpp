#include "Point.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int MAXPOINTS = 3;
const string filename = "points.txt";

void userIn(vector<Point> & pV) {
	for (int i = 0; i < MAXPOINTS; i++) {
		Point tempP;
		cout << "Point " + to_string(i + 1) + ": ";
		cin >> tempP;
		pV.push_back(tempP);
	}
}

void printPoints(vector<Point> & pV) {
	for (int i = 0; i < pV.size(); i++) {
		cout << pV[i];
	}
}

void savePoints(vector<Point> & pV) {
	
	ofstream ostr(filename.c_str());

	for (int i = 0; i < pV.size(); i++) {
		ostr << pV[i];
	}
	ostr << '|';
}

void loadPoints(vector<Point> & pV) {
	ifstream istr(filename);
	Point tempPoint;
	while (istr.peek() != '|' && !istr.eof()){
		istr >> tempPoint;
		pV.push_back(tempPoint);
	}
}

bool isEqual(vector <Point> & vA, vector <Point> & vB) {
	if (vA.size() != vB.size()) return false;
	for (int i = 0; i < vA.size(); i++) {
		if (vA[i] != vB[i]) return false;
	}
	return true;
}

int main() {
	try {
		vector <Point> points;
		userIn(points);
		printPoints(points);
		savePoints(points);
	
		vector<Point> points2;
		loadPoints(points2);
		printPoints(points2);

		if (isEqual(points, points2)) {
			cout << "Is Eqaul! :)";
		}

		// keep window open
		char ch;
		cin >> ch;
	}
	catch (runtime_error &e) {
		cerr << e.what();
		
		cout << "\nquit: q\n";
		char ch = 0;
		while (ch != 'q') {
			cin >> ch;
		}
	}
}