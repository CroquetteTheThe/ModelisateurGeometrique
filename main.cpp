#include <iostream>
#include "Window.h"
#include "Shape.h"
#include "OFFReader.h"

int main(int argc, char **argv) {
	auto window = new Window(&argc, argv, "TP1 - Orval Touitou", 600, 600);
	auto reader = OFFReader();
	window->add(reader.fromFile("../resources/teapot.off"));
	window->show();
	return EXIT_SUCCESS;
}