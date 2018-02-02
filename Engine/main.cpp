#include <headers.h>

#include "Application.h"

FILE *stdStream;

int main() {
	// Redirect stderr to stdout.txt
	//freopen_s(&stdStream, "stdout.txt", "w", stderr);

	Application app;

	try {
		app.run();
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}

	//fclose(stdStream);

	//auto out = helper::readFile("stdout.txt");
	//if (!out.empty())
	//{
	//	std::cout << out.data();
		system("pause");
//	}

	return EXIT_SUCCESS;
}