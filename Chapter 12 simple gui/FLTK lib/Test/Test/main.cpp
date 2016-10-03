#pragma once
#include <iostream>

#include "Window.h"


int main() {
	Graph_lib::Point p1(100, 100);

	Graph_lib::Window window1(p1, 300, 300, "label");



	return Fl::run();
}
