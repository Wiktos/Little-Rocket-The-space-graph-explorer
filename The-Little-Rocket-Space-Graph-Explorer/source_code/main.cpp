#ifdef _WIN32
#define GLEW_STATIC  
#endif

#include <main_includes.h>

int main(int args, char* argv[]) {

	#define TESTS_ON
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
		builder.setTitle("The Little Rocket - Space Graph Explorer");
		builder.setWidth(1200);
		builder.setHeight(800);
		builder.setFramebufferSizeCallback([](GLFWwindow*, int w, int h)->void {
			glViewport(0, 0, w, h);
		});

		Scene mainScene = builder.createScene();
		OpenGLApplication app;
		app.makeContextCurrent(mainScene);

		OpenGLApplication::initGLEW();

		UndirectedMap map(11, 8);
		map.regenerate(6);
		UndirectedMapView mapView(map);
		mainScene.attachObjects(mapView.getObjects());

		LittleRocket rocket(LITTLE_ROCKET_MODEL_OBJ_PATH, LITTLE_ROCKET_MODEL_VERTEX_SHADER_PATH, LITTLE_ROCKET_MODEL_FRAGMENT_SHADER_PATH);
		mainScene.attachObjects(rocket.getObject());

		Camera camera({ { 0.f, 3.f, 9.f }, { 0.f, 0.f, -1.f }, { 0.f, 1.f, 0.f } });
		mainScene.attachCamera(std::make_shared<Camera>(camera));

		SceneController controller(&mainScene);
		controller.registerControlMethod(GLFW_KEY_ESCAPE, [&app]() {
			app.setApplicationShouldClose(GL_TRUE);
		});

		std::thread rocketMovement([&](){
			AlgorithmMovement movement(new DepthFirstSearch (&map, UndirectedMap::START_NODE_IDX));
			movement(mapView, rocket, mainScene.getCamera(), app, map.END_NODE_IDX);
		}); 

		std::shared_ptr<Skybox> skybox(new Skybox(SKYBOX_VERTEX_SHADER_PATH, SKYBOX_FRAGMENT_SHADER_PATH));
		skybox->scale(glm::vec3(100.f, 100.f, 100.f));
		mainScene.attachObject(skybox);

		while (!app.shouldAppBeClosed()) {
			app.updateDeltaTime();
			controller.pollEvents();

			mainScene.clearColor({ .5f, 0.2f, 1.0f, .0f });
			mainScene.clearBuffers({ GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT });
			mainScene.drawObjects();
			
			mainScene.swapBuffers();
		}

		rocketMovement.join();
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