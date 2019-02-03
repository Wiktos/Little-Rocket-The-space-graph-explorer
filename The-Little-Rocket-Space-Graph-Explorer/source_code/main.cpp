#ifdef _WIN32
	#define GLEW_STATIC  
#endif

#include <main_include.h>

int main(int args, char* argv[]) {

	//checks memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

//#define TESTS_ON
#ifdef TESTS_ON
	std::cout << "Unit tests : " << __DATE__ << ' ' << __TIME__ << std::endl;
	ugraph_test::performAllTests();
	umap_test::performAllTests();
	dfs_test::testSearching();
#endif // TESTS_ON

	try	{
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

		while (!app.shouldAppBeClosed()) {
			controller.pollEvents();

			mainScene.clearColor({ .3f, 0.5f, 0.8f, .0f });
			mainScene.clearBuffers({ GL_COLOR_BUFFER_BIT });

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