#ifdef _WIN32
	#define GLEW_STATIC  
#endif

//#define TESTS_ON

#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "../tests/map/undirectedgraph_tests.h"
#include "../tests/map/undirected_map_tests.h"
#include "../tests/algorithms//dfs_test.h"

int main(int args, char* argv[]) {

	//checks memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#ifdef TESTS_ON
	std::cout << "Unit tests : " << __DATE__ << ' ' << __TIME__ << std::endl;
	ugraph_test::performAllTests();
	umap_test::performAllTests();
	dfs_test::testSearching();
#endif // TESTS_ON

	try	{
		if (glfwInit() != GL_TRUE) {
			throw std::runtime_error("Fail to init GLFW");
		}

		glfwWindowHint(GLFW_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

		GLFWwindow* window = glfwCreateWindow(800, 600, "The Little Rocket - The Space Graph Explorer", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		glewExperimental = true;
		if (glewInit() != GLEW_OK) {
			throw std::runtime_error("Fail to init GLEW");
		}

		glViewport(0, 0, 800, 600);
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();

			glClearColor(.3f, 0.5f, 0.8f, .0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window);
		}

	}
	catch (const std::runtime_error& ex) {
		std::cerr << ex.what();
	}

	glfwTerminate();

	return 0;
}