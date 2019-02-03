#ifdef _WIN32
	#define GLEW_STATIC  
#endif

#include <main_include.h>

int main(int args, char* argv[]) {

//#define TESTS_ON
#ifdef TESTS_ON
	//checks memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	std::cout << "Unit tests : " << __DATE__ << ' ' << __TIME__ << std::endl;
	ugraph_test::performAllTests();
	umap_test::performAllTests();
	dfs_test::testSearching();
#endif // TESTS_ON

	try {
		OpenGLApplication::initGLFW();

		SceneBuilder builder;
		builder.addSceneHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
		builder.setTitle("The Little Rocket - The Space Graph Explorer");
		builder.setFramebufferSizeCallback([](GLFWwindow*, int w, int h)->void{
			glViewport(0, 0, w, h);
		});

		Scene mainScene = builder.createScene();
		OpenGLApplication app;
		app.makeContextCurrent(mainScene);

		OpenGLApplication::initGLEW();

		SceneController controller(&mainScene);
		controller.registerControlMethod(GLFW_KEY_ESCAPE, [&app]() {
			app.setApplicationShouldClose(GL_TRUE);
		});

		GraphNodeView singleNode("source_code/visualisation/shaders/node_vertex.vert",
			"source_code/visualisation/shaders/node_fragment.frag");
		singleNode.rotate(85.f, glm::vec3(1.f, 0.f, 0.f));
		mainScene.attachObject(&singleNode);

		GraphEdgeView singleEdge({.5f, .0f, .0f}, { -0.5f, .0f, .0f },
			"source_code/visualisation/shaders/edge_vertex.vert", 
			"source_code/visualisation/shaders/edge_fragment.frag");
		mainScene.attachObject(&singleEdge);

		while (!app.shouldAppBeClosed()) {
			controller.pollEvents();

			mainScene.clearColor({ .5f, 0.2f, 1.0f, .0f });
			mainScene.clearBuffers({ GL_COLOR_BUFFER_BIT });

			mainScene.drawObjects();

			mainScene.swapBuffers();
		}

	}
	catch (const std::runtime_error& ex) {
		std::cerr << ex.what();
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << '\n';
	}
	catch (...) {
		std::cerr << "Unknown exception\n";
	}

	return 0;
}